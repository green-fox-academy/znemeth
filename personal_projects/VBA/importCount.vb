Option Explicit

Sub ImportTextFile()
Dim fName As String

fName = Application.GetOpenFilename("Text Files (*.txt), *.txt")
If fName = "False" Then Exit Sub

    With ActiveSheet.QueryTables.Add(Connection:="TEXT;" & fName, _
        Destination:=Range("$A$1"))
            .Name = "sample"
            .FieldNames = True
            .RowNumbers = False
            .FillAdjacentFormulas = False
            .PreserveFormatting = True
            .RefreshOnFileOpen = False
            .RefreshStyle = xlInsertDeleteCells
            .SavePassword = False
            .SaveData = True
            .AdjustColumnWidth = True
            .RefreshPeriod = 0
            .TextFilePromptOnRefresh = False
            .TextFilePlatform = 437
            .TextFileStartRow = 1
            .TextFileParseType = xlDelimited
            .TextFileTextQualifier = xlTextQualifierNone
            .TextFileConsecutiveDelimiter = True
            .TextFileTabDelimiter = False
            .TextFileSemicolonDelimiter = False
            .TextFileCommaDelimiter = True
            .TextFileSpaceDelimiter = True
            .TextFileOtherDelimiter = "" & Chr(10) & ""
            .TextFileColumnDataTypes = Array(1, 1, 1, 1, 1, 1)
            .TextFileTrailingMinusNumbers = True
            .Refresh BackgroundQuery:=False
    

    End With
End Sub

Sub CountRows1()
    Dim last_row As Long
    last_row = Cells(Rows.count, 1).End(xlUp).Row
    MsgBox ("Number of lines: " & last_row)
End Sub

Sub CountUniqueValues()
Dim LstRw As Long, Rng As Range, List As Object
LstRw = Cells(Rows.count, "B").End(xlUp).Row
Set List = CreateObject("Scripting.Dictionary")

For Each Rng In Range("B2:B" & LstRw)
  If Not List.Exists(Rng.Value) Then List.Add Rng.Value, Nothing
Next

MsgBox "There are " & List.count & " unique values in column B excluding header."

End Sub
