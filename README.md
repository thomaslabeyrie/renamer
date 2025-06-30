# renamer

Straightforward CLI tool to format file names.

### Usage

`./renamer <filename>`

' ' (spaces) are replaces with '\_' (underscores).

`My Project.txt` would become `my_project.txt`.

### What's to come

Letting user specify the formatting options.

`./renamer <filename> <separator> <letterformat>`

`<separator>` would let the user choose the character that should seperate words.

`<letterformat>` would let you choose between `capitalize`, `uppercase` or `lowercase`
