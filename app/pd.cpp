//
// Created by Mukesh Kumar Bagariya on 12/10/21.
//
using Spire.Pdf;
using Spire.Pdf.Actions;
namespace AddExpiryDate
{
    class Program
    {
        static void Main(string[] args)
        {
            PdfDocument doc = new PdfDocument();
            doc.Pages.Add();
            string javaScript = "var rightNow = new Date();"
                     + "var endDate = new Date('October 20, 2016 23:59:59');"
                     + "if(rightNow.getTime() > endDate)"
                     + "app.alert('This Document has expired, please contact us for a new one.',1);"
                     + "this.closeDoc();";
            PdfJavaScriptAction js = new PdfJavaScriptAction(javaScript);
            doc.AfterOpenAction = js;
            doc.SaveToFile("ExpiryDate.pdf", FileFormat.PDF);
        }
    }
}
