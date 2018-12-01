# Newtoo

include html/HTMLParser

let html: string = "<html><head><title>Untitled</title></head><body><h1>Table of contents</h1><ul></ul></body></html>"

var data: HTMLParserData = createHTMLParserDataFromString(0, html)
data.finish
data.run

echo html
