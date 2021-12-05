using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace processView
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            setList();
        }


        void setList()
        {
            listView1.Items.Clear();
            System.Diagnostics.Process[] prs = System.Diagnostics.Process.GetProcesses();
            ListViewItem li = null;
            string processname = "";
            string mainmodule = "";
            int cnt = 1;
            ArrayList msapps = new ArrayList();
            msapps.Add("ApplicationFrameHost".ToLower());
            msapps.Add("audiodg".ToLower());
            msapps.Add("conhost".ToLower());
            msapps.Add("csrss".ToLower());
            msapps.Add("dasHost".ToLower());
            msapps.Add("dllhost".ToLower());
            msapps.Add("dwm".ToLower());
            msapps.Add("explorer".ToLower());
            msapps.Add("fontdrvhost".ToLower());
            msapps.Add("IpOverUsbSvc".ToLower());
            msapps.Add("lsass".ToLower());

            msapps.Add("Pen_Tablet".ToLower());
            msapps.Add("Pen_TabletUser".ToLower());
            msapps.Add("Pen_TouchUser".ToLower());

            msapps.Add("RuntimeBroker".ToLower());
            msapps.Add("SearchIndexer".ToLower());
            msapps.Add("SearchUI".ToLower());
            msapps.Add("services".ToLower());
            msapps.Add("SettingSyncHost".ToLower());
            msapps.Add("ShellExperienceHost".ToLower());
            msapps.Add("sihost".ToLower());
            msapps.Add("SkypeHost".ToLower());
            msapps.Add("smss".ToLower());
            msapps.Add("spoolsv".ToLower());
            msapps.Add("svchost".ToLower());
            msapps.Add("taskhostw".ToLower());
            msapps.Add("Taskmgr".ToLower());
            msapps.Add("wininet".ToLower());
            msapps.Add("winlogon".ToLower());
            msapps.Add("wmpnetwk".ToLower());
            msapps.Add("WTabletServiceCon".ToLower());

            msapps.Add("idle".ToLower());
            msapps.Add("System".ToLower());
            msapps.Add("wininit".ToLower());
            msapps.Add("wmiprvse".ToLower());
            msapps.Add("smartscreen".ToLower());

            msapps.Add("browser_broker".ToLower());
            msapps.Add("MicrosoftEdge".ToLower());
            msapps.Add("MicrosoftEdgeCP".ToLower());
            msapps.Add("notepad".ToLower());


            string ismsapps = "";
            string pid = "";

            foreach (System.Diagnostics.Process pr in prs)
            {
                processname = pr.ProcessName;
                pid = pr.Id.ToString();

                try
                {
                    mainmodule = pr.MainModule.FileName;

                }
                catch (Exception ee)
                {
                    mainmodule = "";
                }

                if (msapps.Contains(processname.ToLower()))
                {
                    ismsapps = "Y";
                }
                else
                {
                    ismsapps = "N";
                }

                li = new ListViewItem(new string[] { pid, processname, mainmodule, ismsapps });

                listView1.Items.Add(li);
                //cnt++;
            }

        }

        private void listView1_ColumnClick(object sender, ColumnClickEventArgs e)
        {
            if (e.Column == 0)
            {
                //return;
                listView1.Sort();
                return;
            }

            listView1.Columns[e.Column].Text = listView1.Columns[e.Column].Text.Replace(" ▼", "");
            listView1.Columns[e.Column].Text = listView1.Columns[e.Column].Text.Replace(" ▲", "");


            if (this.listView1.Sorting == SortOrder.Ascending || listView1.Sorting == SortOrder.None)
            {
                this.listView1.ListViewItemSorter = new ListViewItemComparer(e.Column, "desc");
                listView1.Sorting = SortOrder.Descending;
                listView1.Columns[e.Column].Text = listView1.Columns[e.Column].Text + " ▼";
            }
            else
            {
                this.listView1.ListViewItemSorter = new ListViewItemComparer(e.Column, "asc");
                listView1.Sorting = SortOrder.Ascending;
                listView1.Columns[e.Column].Text = listView1.Columns[e.Column].Text + " ▲";
            }

            listView1.Sort();


        }

        private void proc_button_Click(object sender, EventArgs e)
        {
            setList();
        }
    }

}
