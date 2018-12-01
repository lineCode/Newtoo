include HTMLParserData

proc run*(data: var HTMLParserData) =
    while data.state == Reception:
        if data.proceed == false:
            continue

        # code ...

        inc data.index # +1
