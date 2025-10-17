# StudyEMA20

StudyEMA20 — пользовательское исследование (study) для Sierra Chart, отображающее две экспоненциальные скользящие средние и контрольный счётчик на основном ценовом графике.

## Возможности
- Строит EMA 20 и EMA 9 с помощью функции `MovingAverage`.
- Контрольный счётчик подтверждает, что обработка текущего бара продолжается и обновляется через фиксированный интервал.
- Скрипты PowerShell автоматизируют сборку, проверку, развертывание и «горячую» замену DLL.
- Поддерживаются конфигурации Release и Debug для MSVC v143 x64.

## Структура репозитория
- `src/EMA20Study.cpp` — основная реализация исследования и вспомогательных функций.
- `scripts/` — утилиты PowerShell (`build`, `deploy`, `hotdeploy`, `verify`, `release`).
- `build/` — артефакты MSBuild (при необходимости можно удалить, будут созданы заново).
- `docs/` — документация проекта (`README.md`, `PROJECT_GUIDE.md`).
- `StudyEMA20.sln`, `StudyEMA20.vcxproj` — файлы решения и проекта Visual Studio.

## Требования
- Заголовки Sierra Chart ACS по пути `C:\2308\ACS_Source\`.
- Visual Studio 2022 с установленным набором инструментов MSVC v143 и доступным MSBuild.
- PowerShell 7+ (`pwsh.exe`).
- Опционально: запущенный Sierra Chart с включённым удалённым управлением по UDP (`127.0.0.1:11099`).

## Быстрый старт
1. Соберите релизную DLL:
   ```powershell
   pwsh .\scripts\build.ps1
   ```
2. Разверните DLL в каталоге данных Sierra Chart:
   ```powershell
   pwsh .\scripts\deploy.ps1
   ```
3. Для оперативной замены используйте горячее развертывание без перезапуска Sierra Chart:
   ```powershell
   pwsh .\scripts\hotdeploy.ps1
   ```

## Описание скриптов
- `scripts/build.ps1` — ищет MSBuild (`vswhere`, PATH или `dotnet msbuild`) и собирает проект.
- `scripts/verify.ps1` — выполняет чистую сборку и проверяет наличие расчётов EMA.
- `scripts/deploy.ps1` — копирует DLL в целевой каталог и при необходимости отправляет команду RELEASE по UDP.
- `scripts/hotdeploy.ps1` — копирует DLL через временный файл и отсылает команды RELEASE/ALLOW для атомарной замены.
- `scripts/release.ps1` — запускает последовательность «сборка + горячее развертывание».

Подробные инструкции и советы по устранению неполадок см. в `docs/PROJECT_GUIDE.md`.
