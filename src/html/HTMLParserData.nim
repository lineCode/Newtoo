type
    HTMLParserPattern =
        enum NoPattern, TagName, AttributeNameOrPrefix, AttributeAfterPrefix, AttributeValue, CommentText, DocumentTypeParams

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
        index: uint64

        tagName: string
        attributes: HTMLParserAttributeList
        text: string

        afterInnerScope: bool
        afterInner: string

proc clearNodeData*(self: var HTMLParserData) =
    self.tagName = ""
    self.attributes = @[]
    self.text = ""
    self.afterInnerScope = false
    self.afterInner = ""

proc upNode*(self: var HTMLParserData) =
    if self.target == self.root: return
    self.clearNodeData
    #target = target.parent

proc newElement*(self: var HTMLParserData) =
    var
        xmlnsPrefix: string
        xmlnsUri: string

    for attr in self.attributes:
        # Тут префикс и название поменялись местами https://www.w3schools.com/xml/xml_namespaces.asp
        if attr.prefix == "xmlns":
            xmlnsPrefix = attr.name
            xmlnsUri = attr.value
            break

    #let ref el: Element = createElementNS(xmlnsUri, self.tagName)
    #for attr in self.attributes:
    #   let ref attrItem: Attr = Attr(attr.name, attr.value, 0, attr.prefix)
    #   el.attributes.appendItem(attrItem)
    #self.target.appendChild(el)
    #self.target = el
    self.clearNodeData

proc newTextNode*(self: var HTMLParserData) =
    #let ref text: Text = createTextNode(self.text)
    #self.target.appendChild(text)
    #self.target = text
    self.clearNodeData

proc newComment*(self: var HTMLParserData) =
    #let ref comment: Comment = createComment(self.text[0..self.text.len-3]) # Создаём комментарий без суффикса ' --'
    #self.target.appendChild(comment)
    #self.target = comment
    self.clearNodeData

proc newDocumentType*(self: var HTMLParserData) =
    #let ref doctype: DocumentType = createDocumentType(self.tagName, "", "")
    #self.target.appendChild(doctype)
    #self.target = doctype
    self.clearNodeData

proc putStyleInner*(self: var HTMLParserData) =
    #self.target.HTMLStyleElement.innerHTML = text
    self.clearNodeData

proc putScriptInner*(self: var HTMLParserData) =
    #self.target.HTMLScriptElement.innerHTML = text
    self.clearNodeData

proc proceed*(self: var HTMLParserData): bool =
    return self.index < self.reference.len.uint64

proc inputChunck*(self: var HTMLParserData, augment: string = "") =
    self.reference.add(augment)


proc state*(self: HTMLParserData): ContentLoadingState {.inline.} = self.state # getter

proc finish*(self: var HTMLParserData) =
    self.state = Finished
proc abort*(self: var HTMLParserData) =
    self.state = Interrupted


proc createHTMLParserDataFromString*(element: uint32, htmlref: string = ""): HTMLParserData =
    new result
    result.state = Reception
    result.pattern = NoPattern
    result.scope = TextScope
    result.freeStringScope = false
    result.quotes = 0.char
    result.target = element
    result.root = element
    result.reference = htmlref
    result.index = 0
    result.tagName = ""
    result.attributes = @[]
    result.text = ""
    result.afterInnerScope = false
    result.afterInner = ""
