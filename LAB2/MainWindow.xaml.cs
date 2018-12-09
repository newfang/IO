using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace IO_GUI
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public class CalData
        {
            public string Desc { get; set; }
            public string Date { get; set; }
            public bool Imp { get; set; }
        }

        CalData curData = new CalData();
        public List<CalData> allList = new List<CalData>();

        public MainWindow()
        {
            InitializeComponent();
        }


        private void Button_Click(object sender, RoutedEventArgs e)
        {
            curData.Desc = TXB_01.Text;
            curData.Date = DB.SelectedDate.Value.Date.ToString();
            curData.Imp = (bool)CHB_01.IsChecked;
            allList.Add(curData);
            LB_01.Items.Add(curData.Date + curData.Desc);
        }

        private void CheckBox_Checked(object sender, RoutedEventArgs e)
        {

        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            foreach (var cData in collection)
            {

            }
        }


    }
}
