Attribute VB_Name = "Module1"
Sub VariableTesting()
Dim X As Integer
Dim Y As Double
Dim Z As String
Dim A As Integer
Dim B As Double
Dim C As String
'Calculations
A = X + Y
B = X + Y
A = X / Y
B = X / Y
A = X * Z
C = X + Y
B = X * C
C = X & " " & Z
A = 500000


End Sub
Sub TypeChange()


ActiveSheet.Cells(4, 3).Value = CStr(ActiveSheet.Cells(4, 2).Value)
ActiveSheet.Cells(4, 4).Value = CDbl(ActiveSheet.Cells(4, 2).Value)
ActiveSheet.Cells(4, 5).Value = CInt(ActiveSheet.Cells(4, 2).Value)
ActiveSheet.Cells(4, 6).Value = CLng(ActiveSheet.Cells(4, 2).Value)

ActiveSheet.Cells(5, 3).Value = CStr(ActiveSheet.Cells(5, 2).Value)
ActiveSheet.Cells(5, 4).Value = CDbl(ActiveSheet.Cells(5, 2).Value)
ActiveSheet.Cells(5, 5).Value = CInt(ActiveSheet.Cells(5, 2).Value)
ActiveSheet.Cells(5, 6).Value = CLng(ActiveSheet.Cells(5, 2).Value)

ActiveSheet.Cells(6, 3).Value = CStr(ActiveSheet.Cells(6, 2).Value)
ActiveSheet.Cells(6, 4).Value = CDbl(ActiveSheet.Cells(6, 2).Value)
ActiveSheet.Cells(6, 5).Value = CInt(ActiveSheet.Cells(6, 2).Value)
ActiveSheet.Cells(6, 6).Value = CLng(ActiveSheet.Cells(6, 2).Value)

ActiveSheet.Cells(7, 3).Value = CStr(ActiveSheet.Cells(7, 2).Value)
ActiveSheet.Cells(7, 4).Value = CDbl(ActiveSheet.Cells(7, 2).Value)
ActiveSheet.Cells(7, 5).Value = CInt(ActiveSheet.Cells(7, 2).Value)
ActiveSheet.Cells(7, 6).Value = CLng(ActiveSheet.Cells(7, 2).Value)


ActiveSheet.Cells(8, 3).Value = CStr(ActiveSheet.Cells(8, 2).Value)
ActiveSheet.Cells(8, 4).Value = CDbl(ActiveSheet.Cells(8, 2).Value)
ActiveSheet.Cells(8, 5).Value = CInt(ActiveSheet.Cells(8, 2).Value)
ActiveSheet.Cells(8, 6).Value = CLng(ActiveSheet.Cells(8, 2).Value)


ActiveSheet.Cells(9, 3).Value = CStr(ActiveSheet.Cells(9, 2).Value)



ActiveSheet.Cells(10, 3).Value = CStr(ActiveSheet.Cells(10, 2).Value)
ActiveSheet.Cells(10, 4).Value = CDbl(ActiveSheet.Cells(10, 2).Value)

ActiveSheet.Cells(10, 6).Value = CLng(ActiveSheet.Cells(10, 2).Value)






End Sub
