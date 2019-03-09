/*
  Скетч к проекту "Рамка Slow Dance"
  Страница проекта (схемы, описания): https://alexgyver.ru/SlowDance_Gyver
  Исходники на GitHub: https://github.com/AlexGyver/SlowDance_Gyver
  Нравится, как написан и закомментирован код? Поддержи автора! https://alexgyver.ru/support_alex/
  Автор: AlexGyver Technologies, 2018
  http://AlexGyver.ru/
*/
/*
   Система работает без прерываний, просто потому что почему бы и нет =)
   Потенциометр является опциональным, можно его не ставить, для этого выставить
   0 параметру USE_POT и настроить желаемый DEF_OFFSET, от которого зависит "скорость" движения
*/

// ------------------ НАСТРОЙКИ ------------------
#define USE_POT 1         // 1-использовать потенциометр для подстройки скорости, 0-нет
#define DEF_OFFSET 50     // разница между частотами (для режима БЕЗ крутилки)
#define PERIOD 5000       // период переключения соленоида, мкс
#define EXPO 400          // длительность вспышки света, мкс

#define LIGHT_PIN 5       // пин драйвера свет
#define DRV_1 6           // пин драйвера 1 соленоид
#define DRV_2 7           // пин драйвера 2 соленоид
#define POT_PIN 5         // пин крутилки частоты света

// --------------- ДЛЯ РАЗРАБОТЧИКОВ ---------------
#define SET_TIMER 500     // период опроса крутилки
boolean flashState, motorState;
uint16_t lightTimer, flashDelay;
uint32_t motorPrev, lightPrev, setPrev;

void setup() {
  setADCrate(2);    // ускоряем analogRead

  // настраиваем пины как выходы
  pinMode(DRV_1, OUTPUT);
  pinMode(DRV_2, OUTPUT);
  pinMode(LIGHT_PIN, OUTPUT);

  // выставляем период работы вспышки
  flashDelay = PERIOD * 2 + DEF_OFFSET;
}

void loop() {
#if (USE_POT == 1)
  // таймер чтения крутилок
  if (millis() - setPrev >= SET_TIMER) {
    setPrev = millis();

    // период света как 2 периода мотора + подстройка
    flashDelay = PERIOD * 2 + analogRead(POT_PIN) - 512;
  }
#endif

  // таймер света
  if (micros() - lightPrev >= lightTimer) {
    lightPrev = micros();

    flashState = !flashState;               // инвертируем состояние вспышки

    // быстрый аналог функции digitalWrite
    // если используете другую модель Arduino (не Nano/UNO/Mini),
    // замените на digitalWrite
    bitWrite(PORTD, LIGHT_PIN, flashState); // подаём на вспышку

    // перенастраиваем таймер согласно состоянию
    if (flashState) lightTimer = EXPO;
    else lightTimer = flashDelay - EXPO;
  }

  // таймер драйвера
  if (micros() - motorPrev >= PERIOD) {
    motorPrev = micros();
    motorState = !motorState;

    // быстрый аналог функции digitalWrite
    // если используете другую модель Arduino (не Nano/UNO/Mini),
    // замените на digitalWrite
    bitWrite(PORTD, DRV_1, motorState);
    bitWrite(PORTD, DRV_2, !motorState);
  }
}

// ускорение чтения с АЦП
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
void setADCrate(byte mode) {
  if ((mode & (1 << 2))) sbi(ADCSRA, ADPS2);
  else cbi(ADCSRA, ADPS2);
  if ((mode & (1 << 1))) sbi(ADCSRA, ADPS1);
  else cbi(ADCSRA, ADPS1);
  if ((mode & (1 << 0))) sbi(ADCSRA, ADPS0);
  else cbi(ADCSRA, ADPS0);
}
