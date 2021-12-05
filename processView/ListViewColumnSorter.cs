using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace processView
{
    class ListViewItemComparer : IComparer
    {
        private int col;
        public string sort = "asc";
        public ListViewItemComparer()
        {
            col = 0;
        }

        public ListViewItemComparer(int column, string sort)
        {
            col = column;
            this.sort = sort;
        }

        public int Compare(object x, object y)
        {
            if (sort == "asc")
            {
                return String.Compare(((ListViewItem)x).SubItems[col].Text, ((ListViewItem)y).SubItems[col].Text);
            }
            else
            {
                return String.Compare(((ListViewItem)y).SubItems[col].Text, ((ListViewItem)x).SubItems[col].Text);
            }
        }
    }
}
