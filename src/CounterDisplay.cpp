#include "StudyEMA20/CounterDisplay.h"

namespace StudyEMA20::CounterDisplay
{
	void UpdateCounterDisplay(
		SCStudyInterfaceRef sc,
		SCSubgraphRef counterSubgraph,
		int horizontalPosition,
		int verticalPosition,
		double updateIntervalSeconds,
		int maxValue)
	{
		if (updateIntervalSeconds <= 0.0)
			updateIntervalSeconds = kIntervalSecondsDefault;

		if (maxValue < 1)
			maxValue = 1;

		int& counter = sc.GetPersistentInt(kPersistCounter);
		SCDateTime& lastUpdate = sc.GetPersistentSCDateTime(kPersistLastUpdate);

		if (lastUpdate == 0)
			lastUpdate = sc.CurrentSystemDateTime;

		const SCDateTime currentTime = sc.CurrentSystemDateTime;
		const double secondsSinceUpdate = currentTime.GetFloatSecondsSinceBaseDate() - lastUpdate.GetFloatSecondsSinceBaseDate();

		if (secondsSinceUpdate >= updateIntervalSeconds)
		{
			const int increments = static_cast<int>(secondsSinceUpdate / updateIntervalSeconds);
			const int modulo = maxValue + 1;
			counter = (counter + increments) % modulo;
			lastUpdate = currentTime;
		}

		if (counter < 0)
			counter = 0;

		if (counterSubgraph.LineWidth <= 0)
			counterSubgraph.LineWidth = kFontSizeDefault;

		SCString counterText;
		counterText.Format("%d", counter);

		sc.AddAndManageSingleTextDrawingForStudy(
			sc,
			false,
			horizontalPosition,
			verticalPosition,
			counterSubgraph,
			true,
			counterText,
			true);
	}
}
