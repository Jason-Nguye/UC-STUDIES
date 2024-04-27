Attribute VB_Name = "Module1"
Sub Moment()
    Dim I As Double
    Dim R As Double
    Dim m As Double
    Dim Object As String

    Object = ActiveCell.Offset(2, 3).Value
    m = ActiveCell.Offset(2, 1).Value
    R = ActiveCell.Offset(2, 2).Value

    If Object = "Sphere" Then
        I = (2 / 5) * m * (R ^ 2)
    End If
    If Object = "Cylinder" Then
        I = (1 / 5) * m * (R ^ 2)
    End If
    If Object = "Hoop" Then
        I = m * (R ^ 2)
    End If

    ActiveCell.Value = I
End Sub


