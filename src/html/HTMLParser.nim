include HTMLParserData

proc run*(data: var HTMLParserData) =
    while true:
        if data.proceed == false:
            if(data.state != Reception): break
            continue

        let sign: char = data.reference[data.index.int]

        # code ...

        inc data.index # +1
