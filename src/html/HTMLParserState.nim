type HTMLParserPattern =
    enum NoPattern, TagNameOrPrefix, TagNameAfterPrefix, AttributeName, AttributeValue

type HTMLParserScope =
    enum Tag, Text, ScriptTagInner, StyleTagInner

type HTMLParserState = ref object
    pattern: HTMLParserPattern # = NoPattern
    scope: HTMLParserScope # = Text
    freeStringScope: bool # = false
    quotes: char

    target: ref object # reference to ``Node`` type

    reference: string
    index: uint64 # = 0
