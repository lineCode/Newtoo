type
    HTMLParserPattern =
        enum NoPattern, TagNameOrPrefix, TagNameAfterPrefix, AttributeNameOrPrefix, AttributeAfterPrefix, AttributeValue

    HTMLParserScope =
        enum TagScope, TextScope, ScriptTagInner, StyleTagInner

    HTMLParserAttributeList = seq[tuple[prefix: string, name: string, value: string]]

    ContentLoadingState =
        enum Reception, Finished, Interrupted

    HTMLParserData* = ref object
        state: ContentLoadingState
        pattern: HTMLParserPattern
        scope: HTMLParserScope
        freeStringScope: bool
        quotes: char

        # references to ``Node`` type
        target: uint32
        root: uint32

        reference: string
        index: uint64 # = 0

        prefix: string
        tagName: string
        attributes: HTMLParserAttributeList
        text: string

proc proceed*(self: var HTMLParserData): bool =
    return self.index < self.reference.len.uint64

proc inputChuck*(self: var HTMLParserData, augment: string = "") =
    self.reference.add(augment)


proc state*(self: HTMLParserData): ContentLoadingState {.inline.} = self.state # getter

proc finish*(self: var HTMLParserData) =
    self.state = Finished
proc abort*(self: var HTMLParserData) =
    self.state = Interrupted


proc createHTMLParserDataFromString*(element: ref object, htmlref: string = ""): HTMLParserData =
    return HTMLParserData
    (
        state: Reception,
        pattern: NoPattern,
        scope: TextScope,
        freeStringScope: false,
        quotes: 0,
        target: element,
        root: element,
        reference: htmlref,
        index: 0,

        prefix: "",
        tagName: "",
        attributes: HTMLParserAttributeList,
        text: ""
    )
