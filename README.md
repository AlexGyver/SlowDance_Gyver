![PROJECT_PHOTO](https://github.com/AlexGyver/SlowDance_Gyver/blob/master/proj_img.jpg)
# Slow Dance - рамка, оживляющая растения
* [Описание проекта](#chapter-0)
* [Папки проекта](#chapter-1)
* [Схемы подключения](#chapter-2)
* [Материалы и компоненты](#chapter-3)
* [Как скачать и прошить](#chapter-4)
* [FAQ](#chapter-5)
* [Полезная информация](#chapter-6)
[![AlexGyver YouTube](http://alexgyver.ru/git_banner.jpg)](https://www.youtube.com/channel/UCgtAOyEQdAyjvm9ATCi_Aig?sub_confirmation=1)

<a id="chapter-0"></a>
## Описание проекта
Растение помещается в рамку и начинает магическим образом шевелиться.
Страница проекта на сайте: https://alexgyver.ru/SlowDance_Gyver/  
   
#### Особенности:
- Подстройка скорости движения крутилкой
- Простая схема

<a id="chapter-1"></a>
## Папки
**ВНИМАНИЕ! Если это твой первый опыт работы с Arduino, читай [инструкцию](#chapter-4)**
- **firmware** - прошивки для Arduino
- **schemes** - схемы подключения компонентов

<a id="chapter-2"></a>
## Схемы
![SCHEME](https://github.com/AlexGyver/SlowDance_Gyver/blob/master/schemes/scheme1.jpg)
![SCHEME](https://github.com/AlexGyver/SlowDance_Gyver/blob/master/schemes/scheme2.jpg)

<a id="chapter-3"></a>
## Материалы и компоненты
### Ссылки оставлены на магазины, с которых я закупаюсь уже не один год
Первые ссылки - в основном магазин Great Wall, вторые - WAVGAT. Покупая в одном магазине, вы экономите на доставке!
- Arduino Nano https://ali.ski/0x6XdI  https://ali.ski/LcnMP
- Потенциометр (10 кОм) https://ali.ski/dTyJD
- Драйвер маленький https://ali.ski/YOq6bK  https://ali.ski/AFgv8y
- Драйвер большой https://ali.ski/ZfPuYX  https://ali.ski/yDzpzA
- Магниты https://ali.ski/cH8_P  https://ali.ski/OMBCQa
- Электромагнит 12V https://ali.ski/ek45R  https://ali.ski/d_SHx
- Блок питания 12V 2A https://ali.ski/OS8itj  https://ali.ski/A_9GO
- Яркая лента (белый) https://ali.ski/NOICmz

## Вам скорее всего пригодится
* [Всё для пайки (паяльники и примочки)](http://alexgyver.ru/all-for-soldering/)
* [Недорогие инструменты](http://alexgyver.ru/my_instruments/)
* [Все существующие модули и сенсоры Arduino](http://alexgyver.ru/arduino_shop/)
* [Электронные компоненты](http://alexgyver.ru/electronics/)
* [Аккумуляторы и зарядные модули](http://alexgyver.ru/18650/)

<a id="chapter-4"></a>
## Как скачать и прошить
* [Первые шаги с Arduino](http://alexgyver.ru/arduino-first/) - ультра подробная статья по началу работы с Ардуино, ознакомиться первым делом!
* Скачать архив с проектом
> На главной странице проекта (где ты читаешь этот текст) вверху справа зелёная кнопка **Clone or download**, вот её жми, там будет **Download ZIP**
* Установить библиотеки в  
`C:\Program Files (x86)\Arduino\libraries\` (Windows x64)  
`C:\Program Files\Arduino\libraries\` (Windows x86)
* **Подключить внешнее питание 5 Вольт**
* Подключить Ардуино к компьютеру
* Запустить файл прошивки (который имеет расширение .ino)
* Настроить IDE (COM порт, модель Arduino, как в статье выше)
* Настроить что нужно по проекту
* Нажать загрузить
* Пользоваться  

## Настройки в коде
    USE_POT 1         // 1-использовать потенциометр для подстройки скорости, 0-нет
    DEF_OFFSET 50     // разница между частотами (для режима БЕЗ крутилки)
    PERIOD 5000       // период переключения соленоида, мкс
    EXPO 400          // длительность вспышки света, мкс

    LIGHT_PIN 5       // пин драйвера свет
    DRV_1 6           // пин драйвера 1 соленоид
    DRV_2 7           // пин драйвера 2 соленоид
    POT_PIN 5         // пин крутилки частоты света
	
<a id="chapter-5"></a>
## FAQ
### Основные вопросы
В: Как скачать с этого грёбаного сайта?  
О: На главной странице проекта (где ты читаешь этот текст) вверху справа зелёная кнопка **Clone or download**, вот её жми, там будет **Download ZIP**

В: Скачался какой то файл .zip, куда его теперь?  
О: Это архив. Можно открыть стандартными средствами Windows, но думаю у всех на компьютере установлен WinRAR, архив нужно правой кнопкой и извлечь.

В: Я совсем новичок! Что мне делать с Ардуиной, где взять все программы?  
О: Читай и смотри видос http://alexgyver.ru/arduino-first/

В: Вылетает ошибка загрузки / компиляции!
О: Читай тут: https://alexgyver.ru/arduino-first/#step-5

В: Сколько стоит?  
О: Ничего не продаю.

### Вопросы по этому проекту

<a id="chapter-6"></a>
## Полезная информация
* [Мой сайт](http://alexgyver.ru/)
* [Основной YouTube канал](https://www.youtube.com/channel/UCgtAOyEQdAyjvm9ATCi_Aig?sub_confirmation=1)
* [YouTube канал про Arduino](https://www.youtube.com/channel/UC4axiS76D784-ofoTdo5zOA?sub_confirmation=1)
* [Мои видеоуроки по пайке](https://www.youtube.com/playlist?list=PLOT_HeyBraBuMIwfSYu7kCKXxQGsUKcqR)
* [Мои видеоуроки по Arduino](http://alexgyver.ru/arduino_lessons/)