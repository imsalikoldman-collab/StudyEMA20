#include "sierrachart.h"
#include "StudyEMA20/CounterDisplay.h"

using namespace StudyEMA20::CounterDisplay;

SCDLLName("Study EMA 20")

SCSFExport scsf_EMA20Study(SCStudyInterfaceRef sc)
{
	SCSubgraphRef SubgraphEMA20 = sc.Subgraph[0];
	SCSubgraphRef SubgraphEMA9 = sc.Subgraph[1];
	SCSubgraphRef SubgraphCounter = sc.Subgraph[2];

	SCInputRef InputData = sc.Input[0];
	SCInputRef InputLengthEMA20 = sc.Input[1];
	SCInputRef InputLengthEMA9 = sc.Input[2];
	SCInputRef InputCounterHorizontal = sc.Input[3];
	SCInputRef InputCounterVertical = sc.Input[4];
	SCInputRef InputCounterInterval = sc.Input[5];
	SCInputRef InputCounterMaxValue = sc.Input[6];

	const int CounterHorizontalDefault = kHorizontalDefault;
	const int CounterVerticalDefault = kVerticalDefault;
	const double CounterIntervalDefault = kIntervalSecondsDefault;
	const int CounterMaxValueDefault = kMaxValueDefault;
	const int CounterFontSizeDefault = kFontSizeDefault;
	const COLORREF EmaColor = RGB(0, 122, 255);
	const COLORREF CounterPrimaryColor = RGB(255, 140, 0);
	const COLORREF CounterSecondaryColor = RGB(0, 0, 0);

	if (sc.SetDefaults)
	{
		sc.GraphName = "EMA 20 Study";
		sc.StudyDescription = "EMA 20 and EMA 9 with counter overlay.";
		sc.AutoLoop = 1;
		sc.GraphRegion = 0;
		sc.UpdateAlways = 1;

		SubgraphEMA20.Name = "EMA 20";
		SubgraphEMA20.DrawStyle = DRAWSTYLE_LINE;
		SubgraphEMA20.PrimaryColor = EmaColor;
		SubgraphEMA20.LineWidth = 2;

		SubgraphEMA9.Name = "EMA 9";
		SubgraphEMA9.DrawStyle = DRAWSTYLE_LINE;
		SubgraphEMA9.PrimaryColor = EmaColor;
		SubgraphEMA9.LineWidth = 2;

		SubgraphCounter.Name = "Counter Display";
		SubgraphCounter.DrawStyle = DRAWSTYLE_CUSTOM_TEXT;
		SubgraphCounter.PrimaryColor = CounterPrimaryColor;
		SubgraphCounter.SecondaryColor = CounterSecondaryColor;
		SubgraphCounter.SecondaryColorUsed = 0;
		SubgraphCounter.LineWidth = CounterFontSizeDefault;
		SubgraphCounter.DisplayNameValueInWindowsFlags = 0;
		SubgraphCounter.DrawZeros = 0;

		InputData.Name = "Input Data";
		InputData.SetInputDataIndex(SC_LAST);

		InputLengthEMA20.Name = "Length EMA 20";
		InputLengthEMA20.SetInt(20);
		InputLengthEMA20.SetIntLimits(1, 2000);

		InputLengthEMA9.Name = "Length EMA 9";
		InputLengthEMA9.SetInt(9);
		InputLengthEMA9.SetIntLimits(1, 2000);

		InputCounterHorizontal.Name = "Counter Horizontal Position";
		InputCounterHorizontal.SetInt(CounterHorizontalDefault);
		InputCounterHorizontal.SetIntLimits(CounterHorizontalDefault, CounterHorizontalDefault);

		InputCounterVertical.Name = "Counter Vertical Position";
		InputCounterVertical.SetInt(CounterVerticalDefault);
		InputCounterVertical.SetIntLimits(CounterVerticalDefault, CounterVerticalDefault);

		InputCounterInterval.Name = "Counter Update Interval (Seconds)";
		InputCounterInterval.SetFloat(CounterIntervalDefault);
		InputCounterInterval.SetFloatLimits(CounterIntervalDefault, CounterIntervalDefault);

		InputCounterMaxValue.Name = "Counter Max Value";
		InputCounterMaxValue.SetInt(CounterMaxValueDefault);
		InputCounterMaxValue.SetIntLimits(CounterMaxValueDefault, CounterMaxValueDefault);

		return;
	}

	SubgraphEMA20.DrawStyle = DRAWSTYLE_LINE;
	SubgraphEMA20.PrimaryColor = EmaColor;
	SubgraphEMA20.LineWidth = 1;

	SubgraphEMA9.DrawStyle = DRAWSTYLE_LINE;
	SubgraphEMA9.PrimaryColor = EmaColor;
	SubgraphEMA9.LineWidth = 1;

	SubgraphCounter.DrawStyle = DRAWSTYLE_CUSTOM_TEXT;
	SubgraphCounter.PrimaryColor = CounterPrimaryColor;
	SubgraphCounter.SecondaryColor = CounterSecondaryColor;
	SubgraphCounter.LineWidth = CounterFontSizeDefault;
	SubgraphCounter.DisplayNameValueInWindowsFlags = 0;
	SubgraphCounter.DrawZeros = 0;

	InputCounterHorizontal.SetInt(CounterHorizontalDefault);
	InputCounterVertical.SetInt(CounterVerticalDefault);
	InputCounterInterval.SetFloat(CounterIntervalDefault);
	InputCounterMaxValue.SetInt(CounterMaxValueDefault);

	const int EMA20Length = InputLengthEMA20.GetInt();
	const int EMA9Length = InputLengthEMA9.GetInt();
	const int DataIndex = InputData.GetInputDataIndex();

	int MaximumLength = EMA20Length;
	if (EMA9Length > MaximumLength)
		MaximumLength = EMA9Length;

	sc.DataStartIndex = MaximumLength - 1;

	sc.MovingAverage(sc.BaseDataIn[DataIndex], SubgraphEMA20, MOVAVGTYPE_EXPONENTIAL, EMA20Length);
	sc.MovingAverage(sc.BaseDataIn[DataIndex], SubgraphEMA9, MOVAVGTYPE_EXPONENTIAL, EMA9Length);

	if (sc.IsFullRecalculation)
	{
		sc.GetPersistentInt(1) = 0;
		sc.GetPersistentSCDateTime(2) = sc.CurrentSystemDateTime;
	}

	if (sc.Index == sc.ArraySize - 1)
	{
		UpdateCounterDisplay(
			sc,
			SubgraphCounter,
			InputCounterHorizontal.GetInt(),
			InputCounterVertical.GetInt(),
			InputCounterInterval.GetFloat(),
			InputCounterMaxValue.GetInt());
	}
}
