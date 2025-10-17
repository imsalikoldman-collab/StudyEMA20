# Примеры из каталога `examples/`

Ниже приведены эталонные файлы Sierra Chart ACSIL, размещённые в `examples/`. Каждый `@usage` описывает, для чего можно использовать соответствующий пример: как справочник по оформлению кода и по корректному применению объектов/функций ACSIL.

@usage: examples/Template.cpp — минимальный каркас кастомного исследования; показывает базовую структуру `SCSFExport` и стиль оформления.
@usage: examples/ExampleCustomStudies.cpp — коллекция готовых исследований; полезна для разбора различных паттернов работы с подграфами и входами.
@usage: examples/SCStudyFunctions.cpp — расширенный набор вспомогательных функций Sierra Chart; ориентир по сигнатурам и правильному вызову `sc`-методов.
@usage: examples/SCStudyFunctions.h — заголовок для `SCStudyFunctions.cpp`, демонстрирует организацию прототипов и комментариев.
@usage: examples/SCString.h — пример работы с `SCString` и связанными утилитами строк.
@usage: examples/sierrachart.h — основной заголовок ACSIL; используется как справочник по типам, структурам и константам.
@usage: examples/scconstants.h — перечень констант ACSIL; пригодится при настройке графиков, цветов и типов линий.
@usage: examples/scstructures.h — эталон по структурам данных Sierra Chart (например, `s_BarPeriod`, `s_UseTool`).
@usage: examples/scdatetime.h — вспомогательные функции и структуры работы со временем и датой.
@usage: examples/sccolors.h — примеры определения цветов и палитр.
@usage: examples/ACSILCustomChartBars_Example.cpp — демонстрация кастомных баров и альтернативной визуализации данных.
@usage: examples/ACSILCustomChartBars.h — заголовочные определения для кастомных баров.
@usage: examples/ACSILDepthBars.h — пример реализации глубинных баров (Depth Bars) и работы с книгой заявок.
@usage: examples/ACSILSpreadsheetInteraction.cpp — показ взаимодействия с Spreadsheet Study.
@usage: examples/AutomatedTradeManagementBySubgraph.cpp — эталон автоматического управления сделками на основе значений подграфов.
@usage: examples/CandleStickPatternNames.cpp — перечисление паттернов свечей и работа с текстовыми ресурсами.
@usage: examples/CandleStickPatternNames.h — заголовок для перечислений паттернов, пример именования и структурирования констант.
@usage: examples/CustomChart.cpp — создание пользовательских графиков и нестандартных типов баров.
@usage: examples/GDIExample.cpp — применение GDI для кастомного рисования поверх графика.
@usage: examples/IntradayRecord.h — структура записи тиковых данных; ориентир по полям и типам.
@usage: examples/OrderEntryStudies.cpp — набор примеров по автоматизированному вводу ордеров.
@usage: examples/RequestValuesFromServerAndDraw.cpp — образец запроса данных с сервера и отрисовки результата.
@usage: examples/SpreadOrderEntry.cpp — логика ввода спредовых ордеров.
@usage: examples/Studies.cpp — большая коллекция стандартных исследований Sierra Chart (release 1).
@usage: examples/Studies2.cpp — продолжение набора стандартных исследований (release 2).
@usage: examples/Studies3.cpp — продолжение набора стандартных исследований (release 3).
@usage: examples/Studies4.cpp — продолжение набора стандартных исследований (release 4).
@usage: examples/Studies5.cpp — продолжение набора стандартных исследований (release 5).
@usage: examples/Studies6.cpp — продолжение набора стандартных исследований (release 6).
@usage: examples/Studies7.cpp — продолжение набора стандартных исследований (release 7).
@usage: examples/Studies8.cpp — продолжение набора стандартных исследований (release 8).
@usage: examples/Systems.cpp — примеры торговых систем и сигналов.
@usage: examples/TickIndex.cpp — расчёт и отрисовка тик-индекса.
@usage: examples/TradingSystem.cpp — комплексный пример торговой системы.
@usage: examples/TradingSystemBasedOnAlertCondition.cpp — торговая система, основанная на условиях Alert Condition.
@usage: examples/TradingTriggeredLimitOrderEntry.cpp — логика триггерных лимитных ордеров.
@usage: examples/VAPContainer.h — пример контейнера для Volume at Price.
@usage: examples/SCSymbolData.h — структуры данных по инструментам и символам.

Используйте эти файлы как справочник при разработке, чтобы выдерживать одинаковый стиль и корректно применять API Sierra Chart.
