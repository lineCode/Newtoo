[Constructor(CSSStyleDeclaration? decl)]

interface StyleMetrics
{
    const short Inherit = 0x7FFD;
    const short Initial = 0x7FFE;
    const short Unset = 0x7FFF;

    readonly attribute unsigned long length; // virtual
    DOMString item(unsigned long index); // virtual

    DOMString getPropertyValue(DOMString propertyID); // virtual
    void setPropertyValue(DOMString propertyID, DOMString value); // virtual

    const char NoKeyword = 0x7FFA;

    static CSSOMString keywordToString(short value);
    static short keywordFromString(CSSOMString str);
    static boolean isKeyword(CSSOMString str);
};

typed enum Unit
{
    // Физические единицы длины
    
    "In", // 96px,
    "Cm", // 96px/2.54
    "Mm", // 96px/2.54/10
    "Q", // 96px/2.54/10/40
    "Pt", // 1/72in
    "Pc", // 12pt
    "Px",

    "Deg",
    "Grad",
    "Rad",
    "Turn"

    // Относительные единицы длины

    "Percentages",
    "Rem",
    "Em",
    "Ex",
    "Ch",
    "Vw",
    "Vh",
    "Vmin",
    "Vmax",
    "Fr"
};

[Constructor(double aValue, Unit aUnit)]
interface NumericValue
{
    [SameObject] attribute double value;
    [SameObject] attribute Unit unit;

    double toPx(optional double relativeValue);
    CSSOMString toString();

    static NumericValue fromString(CSSOMString str);
};

enum TimeUnit
{
    "Minutes",
    "Seconds",
    "Milliseconds"
};

[Constructor(unsigned long aNumber, TimeUnit aUnit)]
interface PeriodValue
{
    [SameObject] attribute double number;
    [SameObject] attribute TimeUnit unit;

    unsigned long toMilliseconds();
    CSSOMString toString();

    static PeriodValue fromString(CSSOMString str);
};

typed enum ColorKeyword
{
    "AliceBlue",
    "AntiqueWhite",
    "Aqua",
    "Aquamarine",
    "Azure",
    "Beige",
    "Bisque",
    "Black",
    "BlanchedAlmond",
    "Blue",
    "BlueViolet",
    "Brown",
    "BurlyWood",
    "CadetBlue",
    "Chartreuse",
    "Chocolate",
    "Coral",
    "CornflowerBlue",
    "Cornsilk",
    "Crimson",
    "Aqua",
    "DarkBlue",
    "DarkCyan",
    "DarkGoldenrod",
    "DarkGray",
    "DarkGreen",
    "DarkKhaki",
    "DarkMagenta",
    "DarkOliveGreen",
    "DarkOrange",
    "DarkOrchid",
    "DarkRed",
    "DarkSalmon",
    "DarkSeaGreen",
    "DarkSlateBlue",
    "DarkSlateGray",
    "DarkTurquoise",
    "DarkViolet",
    "DeepPink",
    "DeepSkyBlue",
    "DimGray",
    "DodgerBlue",
    "Firebrick",
    "FloralWhite",
    "ForestGreen",
    "Fuchsia",
    "Gainsboro",
    "GhostWhite",
    "Gold",
    "Goldenrod",
    "Gray",
    "Green",
    "GreenYellow",
    "Honeydew",
    "HotPink",
    "IndianRed",
    "Indigo",
    "Ivory",
    "Khaki",
    "Lavender",
    "LavenderBlush",
    "LawnGreen",
    "LemonChiffon",
    "LightBlue",
    "LightCoral",
    "LightCyan",
    "LightGoldenrodYellow",
    "LightGreen",
    "LightGray",
    "LightPink",
    "LightSalmon",
    "LightSeaGreen",
    "LightSkyBlue",
    "LightSlateGray",
    "LightSteelBlue",
    "LightYellow",
    "Lime",
    "LimeGreen",
    "Linen",
    "Fuchsia",
    "Maroon",
    "MediumAquamarine",
    "MediumBlue",
    "MediumOrchid",
    "MediumPurple",
    "MediumSeaGreen",
    "MediumSlateBlue",
    "MediumSpringGreen",
    "MediumTurquoise",
    "MediumVioletRed",
    "MidnightBlue",
    "MintCream",
    "MistyRose",
    "Moccasin",
    "NavajoWhite",
    "Navy",
    "OldLace",
    "Olive",
    "OliveDrab",
    "Orange",
    "OrangeRed",
    "Orchid",
    "PaleGoldenrod",
    "PaleGreen",
    "PaleTurquoise",
    "PaleVioletRed",
    "PapayaWhip",
    "PeachPuff",
    "Peru",
    "Pink",
    "Plum",
    "PowderBlue",
    "Purple",
    "Red",
    "RosyBrown",
    "RoyalBlue",
    "SaddleBrown",
    "Salmon",
    "SandyBrown",
    "SeaGreen",
    "SeaShell",
    "Sienna",
    "Silver",
    "SkyBlue",
    "SlateBlue",
    "SlateGray",
    "Snow",
    "SpringGreen",
    "SteelBlue",
    "Tan",
    "Teal",
    "Thistle",
    "Tomato",
    "Turquoise",
    "Violet",
    "Wheat",
    "White",
    "WhiteSmoke",
    "Yellow",
    "YellowGreen",

    "Specified" // RGBA
};

dictionary RGBColor
{
    ocetet aRed;
    ocetet aGreen;
    ocetet aBlue;
};

dictionary RGBAColor : RGBColor
{
    ocetet aAlpha;
};

[   Constructor(ColorKeyword aKeyword),
    Constructor(CSSOMString hex),
    Constructor(RGBColor rgb),
    Constructor(RGBAColor rgba)
]
interface ColorValue
{
    [SameObject] attribute ColorKeyword keyword;
    [SameObject] attribute long color;

    attribute ocetet red;
    attribute ocetet green;
    attribute ocetet blue;
    [SameObject]
    attribute ocetet alpha;

    CSSOMString toString();

    static ColorValue fromString(CSSOMString str);
};

[Constructor(optional short aKeyword = NoKeyword, long val)]
interface IntegerValue
{
    [SameObject] attribute short keyword;
    [SameObject] attribute long value;

    CSSOMString toString();

    static IntegerValue fromString(CSSOMString str);
};

[Constructor(optional short aKeyword = NoKeyword, double val)]
interface FloatValue
{
    [SameObject] attribute short keyword;
    [SameObject] attribute double value;

    CSSOMString toString();

    static IntegerValue fromString(CSSOMString str);
};

[Constructor(optional short aKeyword = NoKeyword, CSSOMString str)]
interface StringValue
{
    [SameObject] attribute short keyword;
    [SameObject] attribute CSSOMString value;

    CSSOMString toString();

    static StringValue fromString(CSSOMString str);
};

typed enum AlignContent
{
    "FlexStart",
    "FlexEnd",
    "Center",
    "SpaceBetween",
    "SpaceAround",
    "SpaceEvenly",
    "Stretch"
};
typed enum AlignItems
{
    "FlexStart",
    "FlexEnd",
    "Center",
    "Baseline",
    "Stretch"
};
typed enum AlignSelf
{
    "Auto",
    "FlexStart",
    "FlexEnd",
    "Center",
    "Baseline",
    "Stretch"
};

typed enum AnimationDirection
{
    "Normal",
    "Reverse",
    "Alternate",
    "AlternateReverse"
};

typed enum AnimationFillMode
{
    "None",
    "Forwards",
    "Backwards",
    "Both"
};

typed enum AnimationPlayState
{
    "Paused",
    "Running"
};

typed enum AnimationTimingFunctionType
{
    "Ease",
    "EaseIn",
    "EaseOut",
    "EaseInOut",
    "Linear",
    "StepStart",
    "StepEnd",
    "Steps",
    "CubicBezier",
};

interface CubicBezierFunction
{
    double item(unsigned long index);
    readonly attribute unsigned long length;
    [CEReactions] void add(double number);
    [CEReactions] void remove(unsigned long index);
    CSSOMString toString();
};

[   Constructor(AnimationTimingFunctionType keyword),
    Constructor(CubicBezierFunction aCubicBezierFunction),
    Constructor(unsigned long aSteps)
]
interface AnimationTimingFunction
{
    [SameObject] attribute AnimationTimingFunctionType type;
    [SameObject] readonly attribute CubicBezierFunction cubicBezierFunction;
    [SameObject] attribute unsigned long steps;

    CSSOMString toString();

    static AnimationTimingFunction fromString(CSSOMString str);
};

typed enum BackfaceVisibility
{
    "Visible",
    "Hidden"
};

typed enum BackgroundAttachmentAxis
{
    "Fixed", "Scroll", "Local" // По-умолчанию Scroll
};

typed enum BackgroundClip
{
    "PaddingBox",
    "BorderBox",
    "ContentBox"
};

typed enum BackgroundImageType
{
    "Url", "None"
};

[Constructor(USVString aUrl]
interface BackgroundImage
{
    [SameObject] attribute BackgroundImageType type;
    [SameObject] attribute USVString url;

    CSSOMString toString();

    static BackgroundImage fromString(CSSOMString str);
};

typed enum BackgroundOriginAxis
{
    "PaddingBox",
    "BorderBox",
    "ContentBox"
};

typed enum BackgroundPositionType
{
    "Left",   // = 0%
    "Center",
    "Right",  // = 100%
    "Top",    // = 0%
    "Bottom",  // = 100%
    "Number"
};

[Constructor(BackgroundPositionType keyword), Constructor(NumericValue aNumber)]
interface BackgroundPositionAxis
{
    [SameObject] attribute BackgroundPositionType type;
    [SameObject] attribute NumericValue number;

    CSSOMString toString();

    static BackgroundPositionAxis fromString(CSSOMString str);
};

typed enum BackgroundRepeatAxisType
{
    "NoRepeat",
    "Repeat",
    "RepeatX",
    "RepeatY",
    "Space",
    "Round",
    "Amount"
};

[Constructor(BackgroundRepeatAxisType keyword), Constructor(unsigned long aAmount)]
interface BackgroundRepeatAxis
{
    [SameObject] attribute BackgroundRepeatAxisType type;
    [SameObject] attribute unsigned long amount;

    CSSOMString toString();
};

[   Constructor(short aKeyword),
    Constructor(BackgroundRepeatAxis aX),
    Constructor(BackgroundRepeatAxis aX, BackgroundRepeatAxis aY)
]
interface BackgroundRepeat
{
    [SameObject] attribute short keyword;
    [SameObject] attribute BackgroundRepeatAxis x;
    [SameObject] attribute BackgroundRepeatAxis y;

    CSSOMString toString();

    static BackgroundRepeat fromString(CSSOMString str);
};

typed enum BackgroundSizeType
{
    "Auto", // По-умолчанию
    "Cover",
    "Contain",
    "Number"
};

[Constructor(BackgroundSizeType keyword), Constructor(NumericValue aNumber)]
interface BackgroundSizeAxis
{
    [SameObject] attribute BackgroundSizeType type;
    [SameObject] attribute NumericValue number;

    CSSOMString toString();
};

[   Constructor(short keyword),
    Constructor(BackgroundSizeAxis aX),
    Constructor(BackgroundSizeAxis aX, BackgroundSizeAxis aY)
]
interface BackgroundSize
{
    [SameObject] attribute short aKeyword;
    [SameObject] attribute BackgroundSizeAxis x;
    [SameObject] attribute BackgroundSizeAxis y;

    CSSOMString toString();

    static BackgroundSize fromString(CSSOMString str);
};

typed enum BorderStyle
{
    "None", // По-умолчанию
    "Hidden",
    "Dotted",
    "Dashed",
    "Solid",
    "Double",
    "Groove",
    "Ridge",
    "Inset",
    "Outset"
};

[   Constructor(short aKeyword),
    Constructor(NumericValue aVertical),
    Constructor(NumericValue aVertical, NumericValue aHorizontal)
]
interface BorderRadius
{
    [SameObject] attribute short keyword;
    [SameObject] attribute NumericValue vertical;
    [SameObject] attribute NumericValue horizontal;

    CSSOMString toString();

    static BorderRadius fromString(CSSOMString str);
};

typed enum BorderCollapse
{
    "Collapse",
    "Separate" // По-умолчанию
};

typedef BorderRadius BorderSpacing;

typed enum BoxSizing
{
    "ContentBox",
    "BorderBox"
};

dictionary ShadowDict
{
    bool aInset;
    long aOffsetX;
    long aOffsetY;
    unsigned long aBlur;
    long aStretch;
    ColorValue aColor;
};

[Constructor(ShadowDict dict)]
interface Shadow
{
    [SameObject] attribute bool inset;
    [SameObject] attribute long offsetX;
    [SameObject] attribute long offsetY;
    [SameObject] attribute unsigned long blur;
    [SameObject] attribute long stretch;
    [SameObject] attribute ColorValue color;
};

interface ShadowList
{
    Shadow? item(unsigned long index);
    readonly attribute unsigned long length;
    [CEReactions] void add(Shadow shadow);
    [CEReactions] void remove(unsigned long index);
};

typed enum BoxShadowType
{
    "None",
    "Specified"
};

interface BoxShadow
{
    [SameObject] attribute BoxShadowType type;
    [SameObject] readonly attribute ShadowList shadows;

    CSSOMString toString();

    static BoxShadow fromString(CSSOMString str);
};

typed enum CaptionSide
{
    "Top", // По-умолчанию
    "Bottom",
    "Left",
    "Right"
};

typed enum Clear
{
    "None",
    "Left",
    "Right",
    "Both"
};

typed enum ClipType
{
    "Auto",
    "Specified"
};

[Constructor(long aY1, long aX2, long aY2, long aX1)]
interface Rect
{
    const long Auto = -1;

    [SameObject] attribute long y1;
    [SameObject] attribute long x2;
    [SameObject] attribute long y2;
    [SameObject] attribute long x1;
};

[Constructor(Rect aRect)]
interface Clip
{
    [SameObject] attribute ClipType type;
    [SameObject] attribute Rect rect;

    CSSOMString toString();

    static Clip fromString(CSSOMString str);
};

typed enum ColumnSpan
{
    "One", // По-умолчанию
    "All"
};

typedef BorderStyle ColumnRuleStyle;

typed enum CounterType
{
    "None",
    "Specified"
};

[Constructor(CSSOMString identifer)]
interface Counter
{
    [SameObject] attribute CounterType type;
    [SameObject] attribute CSSOMString identifer;

    CSSOMString toString();

    static Counter fromString(CSSOMString str);
};

typed enum CursorVariant
{
    "Auto",
    "Crosshair",
    "Default",
    "EResize",
    "Help",
    "Move",
    "NResize",
    "NeResize",
    "NwResize",
    "Pointer",
    "Progress",
    "SResize",
    "SeResize",
    "SwResize",
    "Text",
    "WResize",
    "Wait",
    "Url"
};

[Constructor(CursorVariant aVariant), Constructor(CSSOMString aUrl)]
interface Cursor
{
    [SameObject] attribute CursorVariant variant;
    [SameObject] attribute CSSOMString url;

    CSSOMString toString();

    static Cursor fromString(CSSOMString str);
};

typed enum Direction
{
    "Ltr", // По-умолчанию
    "Rtl"
};

typed enum Display
{
    "Block",
    "Inline", // По-умолчанию
    "Flow",
    "FlowRoot",
    "Table",
    "Flex",
    "Grid",
    "ListItem",
    "TableRowGroup",
    "TableHeaderGroup",
    "TableFooterGroup",
    "TableRow",
    "TableCell",
    "TableColumnGroup",
    "TableColumn",
    "TableCaption",
    "Contents",
    "None",
    "InlineBlock",
    "InlineTable",
    "InlineFlex",
    "InlineGrid"
};

typed enum EmptyCells
{
    "Show", // По-умолчанию
    "Hide"
};

typed enum FlexBasisType
{
    "Auto",
    "Fill",
    "MaxContent",
    "MinContent",
    "FitContent",
    "Content",
    "Number"
};

[Constructor(FlexBasisType keyword), Constructor(NumericValue aNumber)]
interface FlexBasis
{
    [SameObject] attribute FlexBasisType type;
    [SameObject] attribute NumericValue number;

    CSSOMString toString();

    static FlexBasis fromString(CSSOMString str);
};

typed enum FlexDirection
{
    "Row",
    "RowReverse",
    "Column",
    "ColumnReverse"
};

typed enum FlexWrap
{
    "Nowrap",
    "Wrap",
    "WrapReverse"
};

typed enum Float
{
    "Left",
    "Right",
    "None"
};

typed enum FontOptionKeywordValue
{
    "NumberInsteadOfKeyword", // По-умолчанию
    "On",
    "Off"
};

[Constructor(CSSOMString id, FontOptionKeywordValue keyword), Constructor(CSSOMString id, long num)]
interface OpenTypeFontOption
{
    [SameObject] attribute CSSOMString optionID;
    [SameObject] attribute FontOptionKeywordValue keywordValue;
    [SameObject] attribute long value;
};

interface OpenTypeFontOptionList
{
    OpenTypeFontOption? item(unsigned long index);
    readonly attribute unsigned long length;
    [CEReactions] void add(OpenTypeFontOption option);
    [CEReactions] void remove(unsigned long index);
};

typed enum FontFeatureSettingsType
{
    "Specified"
};

[Constructor(FontFeatureSettingsType keyword)]
interface FontFeatureSettings
{
    [SameObject] readonly attribute FontFeatureSettingsType type;
    [SameObject] readonly attribute OpenTypeFontOptionList options;

    CSSOMString toString();

    static FontFeatureSettings fromString(CSSOMString str);
};

typed enum FontKerning
{
    "Auto",
    "Normal",
    "None"
};

typed enum FontStretch
{
    "UltraCondensed",
    "ExtraCondensed",
    "Condensed",
    "SemiCondensed",
    "Normal", // По-умолчанию
    "SemiExpanded",
    "Expanded",
    "ExtraExpanded",
    "UltraExpanded"
};

typed enum FontStyle
{
    "Normal", "Italic", "Oblique"
};

typed enum FontVariant
{
    "Normal",
    "SmallCaps"
};

typed enum FontWeightType
{
    "Normal",
    "Bold",
    "Bolder",
    "Lighter",
    "Number"
};

[Constructor(FontWeightType keyword), Constructor(unsigned long aNumber)]
interface FontWeight
{
    [SameObject] attribute FontWeightType type;
    [SameObject] attribute unsigned long number;

    CSSOMString toString();

    static FontWeight fromString(CSSOMString str);
};

typed enum Hyphens
{
    "None",
    "Manual",
    "Auto"
};

typed enum JustifyContent
{
    "FlexStart",
    "FlexEnd",
    "Center",
    "SpaceBetween",
    "SpaceAround",
    "SpaceEvenly",
    "Stretch"
};

typed enum JustifyItems
{
    "FlexStart",
    "FlexEnd",
    "Center",
    "Baseline",
    "Stretch"
};

typed enum JustifySelf
{
    "Auto",
    "FlexStart",
    "FlexEnd",
    "Center",
    "Baseline",
    "Stretch"
};

typed enum LetterSpacingType
{
    "Normal", // По-умолчанию
    "Number"
};

[Constructor(LetterSpacingType keyword), Constructor(NumericValue aNumber)]
interface LetterSpacing
{
    [SameObject] attribute LetterSpacingType type;
    [SameObject] attribute NumericValue number;

    CSSOMString toString();

    static LetterSpacing fromString(CSSOMString str);
};

typedef LetterSpacing LineHeight;

typed enum LineBreak
{
    "Auto", // По-умолчанию
    "Loose",
    "Normal",
    "Strict"
};

typedef BackgroundImage ListStyleImage;

typed enum ListStylePosition
{
    "Inside",
    "Outside" // По-умолчанию
};

typed enum ListStyleType
{
    "Circle",
    "Disc", // По-умолчанию
    "Square",
    "Armenian",
    "Decimal",
    "DecimalLeadingZero",
    "Georgian",
    "LowerAlpha",
    "LowerGreek",
    "LowerLatin",
    "LowerRoman",
    "UpperAlpha",
    "UpperLatin",
    "UpperRoman",
    "None"
};

typedef BorderStyle OutlineStyle;

typed enum OverflowWrap
{
    "Normal",
    "BreakWord"
};

typed enum Overflow
{
    "Auto",
    "Hidden",
    "Scroll",
    "Visible"
};

typed enum PageBreakAfter
{
    "Always",
    "Auto",
    "Avoid",
    "Left",
    "Right"
};

typedef PageBreakAfter PageBreakBefore;

typed enum PageBreakInside
{
    "Auto",
    "Avoid"
};

typed enum PerspectiveType
{
    "None",
    "Number"
};

[Constructor(PerspectiveType keyword), Constructor(NumericValue aNumber)]
interface Perspective
{
    [SameObject] attribute PerspectiveType type;
    [SameObject] attribute NumericValue number;

    CSSOMString toString();

    static NumericValue fromString(CSSOMString str);
};

typed enum PerspectiveOriginType
{
    "Left",   // = 0%
    "Center",
    "Right",  // = 100%
    "Top",    // = 0%
    "Bottom",  // = 100%
    "Number"
};

[Constructor(PerspectiveOriginType keyword), Constructor(NumericValue aNumber)]
interface PerspectiveOriginAxis
{
    [SameObject] attribute PerspectiveOriginType type;
    [SameObject] attribute NumericValue number;

    CSSOMString toString();
};

[   Constructor(short keyword),
    Constructor(PerspectiveOriginAxis aX),
    Constructor(PerspectiveOriginAxis aX, PerspectiveOriginAxis aY)
]
interface PerspectiveOrigin
{
    [SameObject] attribute short aKeyword;
    [SameObject] attribute PerspectiveOriginAxis x;
    [SameObject] attribute PerspectiveOriginAxis y;

    CSSOMString toString();

    static PerspectiveOrigin fromString(CSSOMString str);
};

typed enum Position
{
    "Absolute",
    "Fixed",
    "Relative",
    "Static",
    "Sticky"
};

typed enum QuotesType
{
    "None",
    "Specified"
};

[   Constructor(QuotesType keyword),
    Constructor(byte aAfter),
    Constructor(byte aAfter, byte aBefore)
]
interface Quotes
{
    [SameObject] attribute QuotesType aType;
    [SameObject] attribute byte after;
    [SameObject] attribute byte before;

    CSSOMString toString();

    static Quotes fromString(CSSOMString str);
};

typed enum Resize
{
    "None",
    "Both",
    "Horizontal",
    "Vertical"
};

typed enum SizeType
{
    "Left",   // = 0%
    "Center",
    "Right",  // = 100%
    "Top",    // = 0%
    "Bottom",  // = 100%
    "Number"
};

[Constructor(SizeType keyword), Constructor(NumericValue aNumber)]
interface SizeOf
{
    [SameObject] attribute SizeType type;
    [SameObject] attribute NumericValue number;

    CSSOMString toString();
};

[   Constructor(short keyword),
    Constructor(SizeOf aWidth),
    Constructor(SizeOf aWidth, SizeOf aHeight)
]
interface Size
{
    [SameObject] attribute short aKeyword;
    [SameObject] attribute SizeOf width;
    [SameObject] attribute SizeOf height;

    CSSOMString toString();

    static Size fromString(CSSOMString str);
};

typed enum TableLayout
{
    "Auto",
    "Fixed"
};

typed enum TextAlign
{
    "Center",
    "Justify",
    "Left",
    "Right",
    "Start",
    "End"
};

typed enum TextDecoration
{
    "LineThrough",
    "Overline",
    "Underline",
    "None"
};

typed enum TextOverflow
{
    "Clip",
    "Ellipsis"
};

typedef BoxShadow TextShadow;

typed enum TextTransform
{
    "Capitalize",
    "Lowercase",
    "Uppercase",
    "None"
};

[   Constructor(short keyword),
    Constructor(PerspectiveOriginAxis aX),
    Constructor(PerspectiveOriginAxis aX, PerspectiveOriginAxis aY),
    Constructor(PerspectiveOriginAxis aX, PerspectiveOriginAxis aY, PerspectiveOriginAxis aZ)
]
interface TransformOrigin
{
    [SameObject] attribute short aKeyword;
    [SameObject] attribute PerspectiveOriginAxis x;
    [SameObject] attribute PerspectiveOriginAxis y;
    [SameObject] attribute PerspectiveOriginAxis z;

    CSSOMString toString();

    static TransformOrigin fromString(CSSOMString str);
};

typed enum TransformStyle
{
    "Flat", // По-умолчанию
    "Preserve3d"
};

typed enum TransformType
{
    "None",
    "Specified"
};

[Destructor, Constructor(unsigned short type)]
interface TransformModifier
{
    const unsigned short TRANSFORM_MATRIX = 1;
    const unsigned short TRANSFORM_ROTATE = 2;
    const unsigned short TRANSFORM_SCALE = 3;
    const unsigned short TRANSFORM_SCALE_X = 4;
    const unsigned short TRANSFORM_SCALE_Y = 5;
    const unsigned short TRANSFORM_SKEW_X = 6;
    const unsigned short TRANSFORM_SKEW_Y = 7;
    const unsigned short TRANSFORM_TRANSLATE = 8;
    const unsigned short TRANSFORM_TRANSLATE_X = 9;
    const unsigned short TRANSFORM_TRANSLATE_Y = 10;

    [SameObject] readonly attribute unsigned short transformType;
    [SameObject] readonly attribute Transform? owner;

    CSSOMString toString(); // virtual
    void remove();
};

[Constructor(double aA, double aB, double aC, double aD, double aTx, double aTy)]
interface TransformMatrix : TransformModifier
{
    [SameObject] attribute double a;
    [SameObject] attribute double b;
    [SameObject] attribute double c;
    [SameObject] attribute double d;
    [SameObject] attribute double tx;
    [SameObject] attribute double ty;

    static TransformMatrix fromString(CSSOMString str);
};

[Constructor(NumericValue aAngle)]
interface TransformRotate : TransformModifier
{
    [SameObject] attribute NumericValue angle;

    static TransformRotate fromString(CSSOMString str);
};

[Constructor(double aSx, optional double aSy)]
interface TransformScale : TransformModifier
{
    [SameObject] attribute double sx;
    [SameObject] attribute double sy;

    static TransformScale fromString(CSSOMString str);
};

[Constructor(double aSx)]
interface TransformScaleX : TransformModifier
{
    [SameObject] attribute double sx;

    static TransformScaleX fromString(CSSOMString str);
};

[Constructor(double aSy)]
interface TransformScaleY : TransformModifier
{
    [SameObject] attribute double sy;

    static TransformScaleY fromString(CSSOMString str);
};

[Constructor(NumericValue aAngle)]
interface TransformSkewX : TransformModifier
{
    [SameObject] attribute NumericValue angle;

    static TransformSkewX fromString(CSSOMString str);
};

[Constructor(NumericValue aAngle)]
interface TransformSkewY : TransformModifier
{
    [SameObject] attribute NumericValue angle;

    static TransformSkewY fromString(CSSOMString str);
};

[Constructor(double aTx, optional double aTy)]
interface TransformTranslate : TransformModifier
{
    [SameObject] attribute double tx;
    [SameObject] attribute double ty;

    static TransformTranslate fromString(CSSOMString str);
};

[Constructor(double aTx)]
interface TransformTranslateX : TransformModifier
{
    [SameObject] attribute double tx;

    static TransformTranslateX fromString(CSSOMString str);
};

[Constructor(double aTy)]
interface TransformTranslateY : TransformModifier
{
    [SameObject] attribute double ty;

    static TransformTranslateY fromString(CSSOMString str);
};

[Destructor]
interface TransformList
{
    TransformModifier? item(unsigned long index);
    readonly attribute unsigned long length;
    [CEReactions] void appendModifier(TransformModifier? modifier);
    [CEReactions] TransformModifier? removeModifier(unsigned long index);
};

[Constructor(TransformType keyword)]
interface Transform
{
    [SameObject] attribute TransformType type;
    [SameObject] readonly attribute TransformList modifiers;

    CSSOMString toString();

    static Transform fromString(CSSOMString str);
};

typed enum TransitionPropertyType
{
    "None",
    "All",
    "Specified"
};

interface PropertyList
{
    CSSOMString item(unsigned long index);
    readonly attribute unsigned long length;
    [CEReactions] void add(CSSOMString property);
    [CEReactions] void remove(unsigned long index);
    CSSOMString toString();
};

[Constructor(TransitionPropertyType keyword)]
interface TransitionProperty
{
    [SameObject] attribute TransitionPropertyType type;
    [SameObject] attribute PropertyList properties;
};

typedef AnimationTimingFunction TransitionTimingFunction;

typed enum UnicodeBidi
{
    "Normal",
    "Embed",
    "BidiOverride"
};

typed enum VerticalAlignType
{
    "Baseline",
    "Bottom",
    "Middle",
    "Sub",
    "Super",
    "TextBottom",
    "TextTop",
    "top"
};

[Constructor(VerticalAlignType keyword), Constructor(NumericValue aNumber)]
interface VerticalAlign
{
    [SameObject] attribute VerticalAlignType type;
    [SameObject] attribute NumericValue number;

    CSSOMString toString();

    static VerticalAlign fromString(CSSOMString str);
};

typed enum Visibility
{
    "Visible",
    "Hidden",
    "Collapse"
};

typed enum WhiteSpace
{
    "Normal",
    "Nowrap",
    "Pre",
    "PreLine",
    "PreWrap"
};

typedef LineBreak WordBreak;

typedef LetterSpacing WordSpacing;

typed enum WordWrap
{
    "Normal",
    "BreakWord"
};

typed enum TextAnchor
{
    "Start",
    "Middle",
    "End"
};

typed enum FillRule
{
    "Nonzero", // По-умолчанию
    "Evenodd"
};

typedef BackgroundImage Marker;

typed enum RadiusAxisType
{
    "None",
    "Number"
};

[Constructor(RadiusAxisType keyword), Constructor(NumericValue aNumber)]
interface RadiusAxis
{
    [SameObject] attribute RadiusAxisType type;
    [SameObject] attribute NumericValue number;

    CSSOMString toString();

    static RadiusAxis fromString(CSSOMString str);
};

typed enum PathDataType
{
    "None",
    "Specified"
};

[Constructor(PathDataType keyword), Constructor(CSSOMString aPath)]
interface PathData
{
    [SameObject] attribute PathDataType type;
    [SameObject] attribute CSSOMString path;

    CSSOMString toString();

    static PathData fromString(CSSOMString str);
};

interface Dasharray
{
    NumericValue item(unsigned long index);
    readonly attribute unsigned long length;
    [CEReactions] void add(NumericValue property);
    [CEReactions] void remove(unsigned long index);
    CSSOMString toString();

    static Dasharray fromString(CSSOMString str);
};

typed enum StrokeLinecap
{
    "Butt", // По-умолчанию
    "Round",
    "Square"
};

typed enum StrokeLinejoin
{
    "Miter", // По-умолчанию
    "MiterClip",
    "Round",
    "Bevel",
    "Arcs"
};

[Constructor(CSSStyleDeclaration? decl)]
interface ElementStyleMetrics : StyleMetrics
{
    const AnimationIterationCount Infinite = -1;

    [SameObject] attribute AlignContent alignContent;
    [SameObject] attribute AlignItems alignItems;
    [SameObject] attribute AlignSelf alignSelf;

    [SameObject] attribute PeriodValue animationDelay;
    [SameObject] attribute AnimationDirection animationDirection;
    [SameObject] attribute PeriodValue animationDuration;
    [SameObject] attribute AnimationFillMode animationFillMode;
    [SameObject] attribute IntegerValue animationIterationCount;
    [SameObject] attribute StringValue animationName;
    [SameObject] attribute AnimationPlayState animationPlayState;
    [SameObject] attribute AnimationTimingFunction animationTimingFunction;

    [SameObject] attribute BackfaceVisibility backfaceVisibility;

    [SameObject] attribute BackgroundAttachment backgroundAttachment;
    [SameObject] attribute BackgroundClip backgroundClip;
    [SameObject] attribute ColorValue backgroundColor;
    [SameObject] attribute BackgroundImage backgroundImage;
    [SameObject] attribute BackgroundOriginAxis backgroundOriginX;
    [SameObject] attribute BackgroundOriginAxis backgroundOriginY;
    [SameObject] attribute BackgroundPositionAxis backgroundPositionX;
    [SameObject] attribute BackgroundPositionAxis backgroundPositionY;
    [SameObject] attribute BackgroundRepeat backgroundRepeat;
    [SameObject] attribute BackgroundSize backgroundSize;

    [SameObject] attribute ColorValue borderBottomColor;
    [SameObject] attribute BorderRadius borderBottomLeftRadius;
    [SameObject] attribute BorderRadius borderBottomRightRadius;
    [SameObject] attribute BorderStyle borderBottomStyle;
    [SameObject] attribute NumericValue borderBottomWidth;
    [SameObject] attribute BorderCollapse borderCollapse;
    [SameObject] attribute ColorValue borderLeftColor;
    [SameObject] attribute BorderStyle borderLeftStyle;
    [SameObject] attribute NumericValue borderLeftWidth;
    [SameObject] attribute ColorValue borderRightColor;
    [SameObject] attribute BorderStyle borderRightStyle;
    [SameObject] attribute NumericValue borderRightWidth;
    [SameObject] attribute BorderSpacing borderSpacing;
    [SameObject] attribute BorderStyle borderTopColor;
    [SameObject] attribute BorderRadius borderTopLeftRadius;
    [SameObject] attribute BorderRadius borderTopRightRadius;
    [SameObject] attribute BorderStyle borderTopStyle;
    [SameObject] attribute NumericValue borderTopWidth;

    [SameObject] attribute NumericValue bottom;
    [SameObject] attribute BoxShadow boxShadow;
    [SameObject] attribute BoxSizing boxSizing;
    [SameObject] attribute CaptionSide captionSide;
    [SameObject] attribute ColorValue caretColor;
    [SameObject] attribute Clear clear;
    [SameObject] attribute Clip clip;
    [SameObject] attribute ColorValue color;

    [SameObject] attribute IntegerValue columnCount;
    [SameObject] attribute columnFill;
    [SameObject] attribute NumericValue columnGap;
    [SameObject] attribute ColorValue columnRuleColor;
    [SameObject] attribute ColumnRuleStyle columnRuleStyle;
    [SameObject] attribute NumericValue columnRuleWidth;
    [SameObject] attribute ColumnSpan columnSpan;
    [SameObject] attribute IntegerValue columnWidth;

    [SameObject] attribute Counter counterIncrement;
    [SameObject] attribute Counter counterReset;
    
    [SameObject] attribute Cursor cursor;
    [SameObject] attribute Direction direction;
    [SameObject] attribute Display display;
    [SameObject] attribute EmptyCells emptyCells;

    [SameObject] attribute FlexBasis flexBasis;
    [SameObject] attribute FlexDirection flexDirection;
    [SameObject] attribute IntegerValue flexGrow;
    [SameObject] attribute IntegerValue flexShrink;
    [SameObject] attribute FlexWrap flexWrap;

    [SameObject] attribute Float cssFloat;

    [SameObject] attribute StringValue fontFamily;
    [SameObject] attribute FontFeatureSettings fontFeatureSettings;
    [SameObject] attribute FontKerning fontKerning;
    [SameObject] attribute NumericValue fontSize;
    [SameObject] attribute FontStretch fontStretch;
    [SameObject] attribute FontStyle fontStyle;
    [SameObject] attribute FontVariant fontVariant;
    [SameObject] attribute FontWeight fontWeight;

    [SameObject] attribute NumericValue height;
    [SameObject] attribute Hyphens hyphens;

    [SameObject] attribute JustifyContent justifyContent;
    [SameObject] attribute JustifyItems justifyItems;
    [SameObject] attribute JustifySelf justifySelf;

    [SameObject] attribute NumericValue left;
    [SameObject] attribute LetterSpacing letterSpacing;
    [SameObject] attribute LineBreak lineBreak;
    [SameObject] attribute LineHeight lineHeight;

    [SameObject] attribute ListStyleImage listStyleImage;
    [SameObject] attribute ListStylePosition listStylePosition;
    [SameObject] attribute ListStyleType listStyleType;

    [SameObject] attribute NumericValue marginBottom;
    [SameObject] attribute NumericValue marginLeft;
    [SameObject] attribute NumericValue marginRight;
    [SameObject] attribute NumericValue marginTop;

    [SameObject] attribute NumericValue maxHeight;
    [SameObject] attribute NumericValue maxWidth;
    [SameObject] attribute NumericValue minHeight;
    [SameObject] attribute NumericValue minWidth;
    [SameObject] attribute FloatValue opacity;

    [SameObject] attribute ColorValue outlineColor;
    [SameObject] attribute NumericValue outlineOffset;
    [SameObject] attribute OutlineStyle outlineStyle;
    [SameObject] attribute NumericValue outlineWidth;

    [SameObject] attribute OverflowWrap overflowWrap;
    [SameObject] attribute Overflow overflowX;
    [SameObject] attribute Overflow overflowY;

    [SameObject] attribute NumericValue paddingBottom;
    [SameObject] attribute NumericValue paddingLeft;
    [SameObject] attribute NumericValue paddingRight;
    [SameObject] attribute NumericValue paddingTop;

    [SameObject] attribute PageBreakAfter pageBreakAfter;
    [SameObject] attribute PageBreakBefore pageBreakBefore;
    [SameObject] attribute PageBreakInside pageBreakInside;

    [SameObject] attribute Perspective perspective;
    [SameObject] attribute PerspectiveOrigin perspectiveOrigin;

    [SameObject] attribute Position position;
    [SameObject] attribute Quotes quotes;
    [SameObject] attribute Resize resize;
    [SameObject] attribute NumericValue right;
    [SameObject] attribute Size size;
    [SameObject] attribute IntegerValue tabSize; // По-умолчаню равно 8
    [SameObject] attribute TableLayout tableLayout;

    [SameObject] attribute TextAlign textAlign;
    [SameObject] attribute TextDecoration textDecoration;
    [SameObject] attribute NumericValue textIndent;
    [SameObject] attribute TextOverflow textOverflow;
    [SameObject] attribute TextShadow textShadow;
    [SameObject] attribute TextTransform textTransform;

    [SameObject] attribute NumericValue top;

    [SameObject] attribute TransformOrigin transformOrigin;
    [SameObject] attribute TransformStyle transformStyle;
    [SameObject] attribute Transform transform;

    [SameObject] attribute PeriodValue transitionDelay;
    [SameObject] attribute PeriodValue transitionDuration;
    [SameObject] attribute TransitionProperty transitionProperty;
    [SameObject] attribute TransitionTimingFunction transitionTimingFunction;

    [SameObject] attribute UnicodeBidi unicodeBidi;
    [SameObject] attribute VerticalAlign verticalAlign;
    [SameObject] attribute Visibility visibility;
    [SameObject] attribute WhiteSpace whiteSpace;
    [SameObject] attribute IntegerValue widows;
    [SameObject] attribute NumericValue width;

    [SameObject] attribute WordBreak wordBreak;
    [SameObject] attribute WordSpacing wordSpacing;
    [SameObject] attribute WordWrap wordWrap;
    
    [SameObject] attribute IntegerValue zIndex;
};

[Constructor(CSSStyleDeclaration? decl)]
interface FirstLetterStyleMetrics : StyleMetrics
{
    [SameObject] attribute BackgroundAttachment backgroundAttachment;
    [SameObject] attribute BackgroundClip backgroundClip;
    [SameObject] attribute ColorValue backgroundColor;
    [SameObject] attribute BackgroundImage backgroundImage;
    [SameObject] attribute BackgroundOriginAxis backgroundOriginX;
    [SameObject] attribute BackgroundOriginAxis backgroundOriginY;
    [SameObject] attribute BackgroundPositionAxis backgroundPositionX;
    [SameObject] attribute BackgroundPositionAxis backgroundPositionY;
    [SameObject] attribute BackgroundRepeat backgroundRepeat;
    [SameObject] attribute BackgroundSize backgroundSize;

    [SameObject] attribute ColorValue borderBottomColor;
    [SameObject] attribute BorderRadius borderBottomLeftRadius;
    [SameObject] attribute BorderRadius borderBottomRightRadius;
    [SameObject] attribute BorderStyle borderBottomStyle;
    [SameObject] attribute NumericValue borderBottomWidth;
    [SameObject] attribute BorderCollapse borderCollapse;
    [SameObject] attribute ColorValue borderLeftColor;
    [SameObject] attribute BorderStyle borderLeftStyle;
    [SameObject] attribute NumericValue borderLeftWidth;
    [SameObject] attribute ColorValue borderRightColor;
    [SameObject] attribute BorderStyle borderRightStyle;
    [SameObject] attribute NumericValue borderRightWidth;
    [SameObject] attribute BorderSpacing borderSpacing;
    [SameObject] attribute BorderStyle borderTopColor;
    [SameObject] attribute BorderRadius borderTopLeftRadius;
    [SameObject] attribute BorderRadius borderTopRightRadius;
    [SameObject] attribute BorderStyle borderTopStyle;
    [SameObject] attribute NumericValue borderTopWidth;

    [SameObject] attribute BoxShadow boxShadow;
    [SameObject] attribute ColorValue color;
    
    [SameObject] attribute Float cssFloat;

    [SameObject] attribute StringValue fontFamily;
    [SameObject] attribute FontFeatureSettings fontFeatureSettings;
    [SameObject] attribute FontKerning fontKerning;
    [SameObject] attribute NumericValue fontSize;
    [SameObject] attribute FontStretch fontStretch;
    [SameObject] attribute FontStyle fontStyle;
    [SameObject] attribute FontVariant fontVariant;
    [SameObject] attribute FontWeight fontWeight;

    [SameObject] attribute LetterSpacing letterSpacing;
    [SameObject] attribute LineHeight lineHeight;

    [SameObject] attribute NumericValue marginBottom;
    [SameObject] attribute NumericValue marginLeft;
    [SameObject] attribute NumericValue marginRight;
    [SameObject] attribute NumericValue marginTop;

    [SameObject] attribute NumericValue paddingBottom;
    [SameObject] attribute NumericValue paddingLeft;
    [SameObject] attribute NumericValue paddingRight;
    [SameObject] attribute NumericValue paddingTop;

    [SameObject] attribute TextDecoration textDecoration;
    [SameObject] attribute TextShadow textShadow;
    [SameObject] attribute TextTransform textTransform;

    [SameObject] attribute VerticalAlign verticalAlign;

    [SameObject] attribute WordSpacing wordSpacing;
};

[Constructor(CSSStyleDeclaration? decl)]
interface FirstLineStyleMetrics : StyleMetrics
{
    [SameObject] attribute BackgroundAttachment backgroundAttachment;
    [SameObject] attribute BackgroundClip backgroundClip;
    [SameObject] attribute ColorValue backgroundColor;
    [SameObject] attribute BackgroundImage backgroundImage;
    [SameObject] attribute BackgroundOriginAxis backgroundOriginX;
    [SameObject] attribute BackgroundOriginAxis backgroundOriginY;
    [SameObject] attribute BackgroundPositionAxis backgroundPositionX;
    [SameObject] attribute BackgroundPositionAxis backgroundPositionY;
    [SameObject] attribute BackgroundRepeat backgroundRepeat;
    [SameObject] attribute BackgroundSize backgroundSize;

    [SameObject] attribute ColorValue color;

    [SameObject] attribute StringValue fontFamily;
    [SameObject] attribute FontFeatureSettings fontFeatureSettings;
    [SameObject] attribute FontKerning fontKerning;
    [SameObject] attribute NumericValue fontSize;
    [SameObject] attribute FontStretch fontStretch;
    [SameObject] attribute FontStyle fontStyle;
    [SameObject] attribute FontVariant fontVariant;
    [SameObject] attribute FontWeight fontWeight;

    [SameObject] attribute LetterSpacing letterSpacing;
    [SameObject] attribute LineHeight lineHeight;

    [SameObject] attribute TextDecoration textDecoration;
    [SameObject] attribute TextShadow textShadow;
    [SameObject] attribute TextTransform textTransform;

    [SameObject] attribute VerticalAlign verticalAlign;

    [SameObject] attribute WordSpacing wordSpacing;
};

[Constructor(CSSStyleDeclaration? decl)]
interface SelectionStyleMetrics : StyleMetrics
{
    [SameObject] attribute ColorValue backgroundColor;
    [SameObject] attribute ColorValue caretColor;
    [SameObject] attribute ColorValue color;
    
    [SameObject] attribute Cursor cursor;

    [SameObject] attribute ColorValue outlineColor;
    [SameObject] attribute NumericValue outlineOffset;
    [SameObject] attribute OutlineStyle outlineStyle;
    [SameObject] attribute NumericValue outlineWidth;

    [SameObject] attribute TextDecoration textDecoration;
    [SameObject] attribute TextShadow textShadow;
};

[Constructor(CSSStyleDeclaration? decl)]
interface SVGElementStyleMetrics : StyleMetrics
{
    [SameObject] attribute ColorValue color;
    
    [SameObject] attribute Cursor cursor;

    [SameObject] attribute Direction direction;

    [SameObject] attribute StringValue fontFamily;
    [SameObject] attribute FontFeatureSettings fontFeatureSettings;
    [SameObject] attribute FontKerning fontKerning;
    [SameObject] attribute NumericValue fontSize;
    [SameObject] attribute FontStretch fontStretch;
    [SameObject] attribute FontStyle fontStyle;
    [SameObject] attribute FontVariant fontVariant;
    [SameObject] attribute FontWeight fontWeight;

    [SameObject] attribute LetterSpacing letterSpacing;
    [SameObject] attribute LineHeight lineHeight;

    [SameObject] attribute FloatValue opacity;

    [SameObject] attribute TextDecoration textDecoration;
    [SameObject] attribute TextOverflow textOverflow;
    [SameObject] attribute TextShadow textShadow;
    [SameObject] attribute TextTransform textTransform;

    [SameObject] attribute NumericValue top;

    [SameObject] attribute TransformOrigin transformOrigin;
    [SameObject] attribute Transform transform;

    [SameObject] attribute UnicodeBidi unicodeBidi;
    [SameObject] attribute VerticalAlign verticalAlign;
    [SameObject] attribute Visibility visibility;
    [SameObject] attribute WhiteSpace whiteSpace;

    [SameObject] attribute WordSpacing wordSpacing;

    // SVG Специфичные свойства

    [SameObject] attribute TextAnchor textAnchor;

    [SameObject] attribute NumericValue cx;
    [SameObject] attribute NumericValue cy;

    [SameObject] attribute NumericValue height;
    [SameObject] attribute NumericValue width;

    [SameObject] attribute NumericValue x;
    [SameObject] attribute NumericValue y;

    [SameObject] attribute NumericValue r;

    [SameObject] attribute RadiusAxis rx;
    [SameObject] attribute RadiusAxis ry;

    [SameObject] attribute PathData d;

    [SameObject] attribute ColorValue fill;
    [SameObject] attribute FloatValue fillOpacity;
    [SameObject] attribute FillRule fillRule;

    [SameObject] attribute RadiusAxis rx;
    [SameObject] attribute RadiusAxis ry;

    [SameObject] attribute Marker markerStart;
    [SameObject] attribute Marker markerMid;
    [SameObject] attribute Marker markerEnd;

    [SameObject] attribute ColorValue stroke;
    [SameObject] attribute Dasharray strokeDasharray;
    [SameObject] attribute NumericValue strokeDashoffset;
    [SameObject] attribute ColorValue strokeLinecap;
    [SameObject] attribute ColorValue strokeLinejoin;
    [SameObject] attribute IntegerValue strokeMitterlimit; // По-умолчанию 4
    [SameObject] attribute FloatValue strokeOpacity;
    [SameObject] attribute IntegerValue strokeWidth;
};