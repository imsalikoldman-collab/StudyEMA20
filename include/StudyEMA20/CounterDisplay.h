#pragma once

#include "sierrachart.h"

namespace StudyEMA20::CounterDisplay
{
	constexpr int kHorizontalDefault = 50;
	constexpr int kVerticalDefault = 50;
	constexpr double kIntervalSecondsDefault = 1.0;
	constexpr int kMaxValueDefault = 65535;
	constexpr int kFontSizeDefault = 48;

	constexpr int kPersistCounter = 1;
	constexpr int kPersistLastUpdate = 2;

	void UpdateCounterDisplay(
		SCStudyInterfaceRef sc,
		SCSubgraphRef counterSubgraph,
		int horizontalPosition,
		int verticalPosition,
		double updateIntervalSeconds,
		int maxValue);
}
