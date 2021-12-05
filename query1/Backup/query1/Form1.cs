using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace query1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            
        }
        private int gwalho_count=0;

        private void button1_Click(object sender, EventArgs e)
        {
            // 변환 버튼
            richTextBox_after.Clear();
            String str = "";
            progressBar1.Value = 0;
            progressBar1.Maximum = richTextBox_before.Lines.Length;

            //richTextBox_after.Lines = new string[richTextBox_before.Lines.Length];
            gwalho_count = 0;
            button1.UseWaitCursor = true;
            
            for (int i = 0; i < richTextBox_before.Lines.Length ; i++)
            {
                progressBar1.Value = i;

                str = richTextBox_before.Lines[i].ToString();

                bool bcheckmainquery=checkmainquery(str);//주요 구문 들여쓰기 체크

                if (!bcheckmainquery)
                {
                    str = "  " + str.Trim();
                }
                else
                {
                    str = str.Trim();
                }

                int leftcount = countleftgwalho(str);
                int rightcount = countrightgwalho(str);
                int gwalho_count_temp = 0;

                int gwalho_count_before = gwalho_count;    //윗줄 카운트 저장 
                //////////
                if (gwalho_count < 0)
                {
                    MessageBox.Show("마이너스가 나왔습니다. 쿼리를 확인하세요.");
                    break;
                }

                ///////////
                bool gwalhobefore = false;

                if (leftcount != 0 || rightcount != 0)
                {
                    if (leftcount == rightcount)
                    {
                        gwalho_count = gwalho_count + leftcount - rightcount;
                        gwalhobefore = false;
                    }
                    else
                    {
                        gwalho_count = gwalho_count + leftcount - rightcount;
                        gwalhobefore = true;
                    }
                }

                if (!gwalhobefore)
                {
                    gwalho_count_temp = gwalho_count;
                }
                else
                {
                    gwalho_count_temp = gwalho_count_before;
                }
                        
                while (gwalho_count_temp != 0)
                {
                    str = "        " + str;
                    gwalho_count_temp--;
                }
          //      richTextBox_after.Text = richTextBox_after.Text + "\r\n" + str;
                richTextBox_after.AppendText(str);
                richTextBox_after.AppendText("\r\n");
            
            }

            if (gwalho_count != 0)
            {
                richTextBox_after.AppendText("-- 레벨이  "+gwalho_count.ToString()+"  남았습니다. 수정하세요.\r\n");
            }

            button1.UseWaitCursor = false;

        }
        private int countleftgwalho(String str)
        {
            while (str.IndexOf('\'') > 0)
            {
                str = countquerystring(str);
            }
            int temp = 0;
            int countleft = 0;
            int gwalho=str.IndexOf('(');

            if (gwalho != -1)
            {
                while (true)
                {
                    temp = str.IndexOf('(', temp + 1);
                    if (temp == -1)
                        break;
                   
                    countleft++;
                }
    
            }
            return countleft;
        }

        private int countrightgwalho(String str)
        {
            while (str.IndexOf('\'') > 0)
            {
                str = countquerystring(str);
            }
            int temp = 0;
            int countright = 0;
            int gwalho = str.IndexOf(')');

            if (gwalho != -1)
            {
                while (true)
                {
                    temp = str.IndexOf(')', temp + 1);
                    if (temp == -1)
                        break;

                    countright++;
                }

            }
            return countright;
        }

        private string countquerystring(string str)
        {
            string temp = str;
            if (str.IndexOf('\'') < 0) return str;

            int start=str.IndexOf('\'');
            temp = temp.Substring(start+1);
            int end = temp.IndexOf('\'');
            temp= str.Substring(start,end+2);
            str = str.Replace(temp, "");
            return str;
        
        
        
        }

        private void linkLabel1_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            System.Diagnostics.Process.Start("http://blog.naver.com/alucard99");

        }
        private bool checkmainquery(string str)
        { 
            bool checkmain=checkBox_mainphase.Checked;
            if (checkmain)
            {
                str = str.Trim()+"                                ";
                str = str.ToLower();
                if (str.Substring(0,7).Equals("select ") ||
                    str.Substring(0, 7).Equals("select/") ||    //힌트 주는 경우 
                    str.Substring(0, 7).Equals("insert ") ||
                    str.Substring(0, 7).Equals("delete ") ||
                    str.Substring(0, 6).Equals("alter ") ||
                    str.Substring(0, 5).Equals("from ") ||
                    str.Substring(0, 6).Equals("where ") ||
                    str.Substring(0, 6).Equals("group ") ||
                    str.Substring(0, 7).Equals("having ") ||
                    str.Substring(0, 6).Equals("union ") ||
                    str.Substring(0, 6).Equals("minus ") ||
                    str.Substring(0, 5).Equals("with ")  ||
                    str.Substring(0, 6).Equals("order ") 

                    )
                    return true;
                else
                    return false;


            }
            else
                return false;
        
        }
    }
}