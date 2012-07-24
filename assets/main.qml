import bb.cascades 1.0

//-- create one page with a label and text
Page
{
    content: Container 
    {
        layout: StackLayout
        {
            layoutDirection: LayoutDirection.TopToBottom
        }

        TextField
        {
            id: inputField
            
            layoutProperties: StackLayoutProperties
            {
                spaceQuota: -1
            }
            
            hintText: "Enter a command"
            
            onCreationCompleted: {
                inputField.requestFocus()
            }
        }
        
        TextArea
        {
            id: outputArea
            
            layoutProperties: StackLayoutProperties
            {
                spaceQuota: 1
            }
            
            editable: false
        }        
    }
}
