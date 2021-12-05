namespace query1
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.richTextBox_before = new System.Windows.Forms.RichTextBox();
            this.richTextBox_after = new System.Windows.Forms.RichTextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.linkLabel1 = new System.Windows.Forms.LinkLabel();
            this.label3 = new System.Windows.Forms.Label();
            this.checkBox_mainphase = new System.Windows.Forms.CheckBox();
            this.progressBar1 = new System.Windows.Forms.ProgressBar();
            this.SuspendLayout();
            // 
            // richTextBox_before
            // 
            this.richTextBox_before.EnableAutoDragDrop = true;
            this.richTextBox_before.ForeColor = System.Drawing.Color.Sienna;
            this.richTextBox_before.Location = new System.Drawing.Point(26, 33);
            this.richTextBox_before.Name = "richTextBox_before";
            this.richTextBox_before.Size = new System.Drawing.Size(1020, 320);
            this.richTextBox_before.TabIndex = 0;
            this.richTextBox_before.Text = "";
            this.richTextBox_before.WordWrap = false;
            // 
            // richTextBox_after
            // 
            this.richTextBox_after.ForeColor = System.Drawing.Color.Black;
            this.richTextBox_after.Location = new System.Drawing.Point(26, 387);
            this.richTextBox_after.Name = "richTextBox_after";
            this.richTextBox_after.Size = new System.Drawing.Size(1020, 320);
            this.richTextBox_after.TabIndex = 1;
            this.richTextBox_after.Text = "";
            this.richTextBox_after.WordWrap = false;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(26, 717);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(138, 23);
            this.button1.TabIndex = 1;
            this.button1.Text = "레벨 맞추기 시작!";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(24, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(29, 12);
            this.label1.TabIndex = 2;
            this.label1.Text = "원본";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(24, 366);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(41, 12);
            this.label2.TabIndex = 2;
            this.label2.Text = "결과물";
            // 
            // linkLabel1
            // 
            this.linkLabel1.AutoSize = true;
            this.linkLabel1.Location = new System.Drawing.Point(915, 717);
            this.linkLabel1.Name = "linkLabel1";
            this.linkLabel1.Size = new System.Drawing.Size(87, 12);
            this.linkLabel1.TabIndex = 3;
            this.linkLabel1.TabStop = true;
            this.linkLabel1.Text = "my homepage";
            this.linkLabel1.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(this.linkLabel1_LinkClicked);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(915, 745);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(89, 12);
            this.label3.TabIndex = 2;
            this.label3.Text = "제작자 : 김철민";
            // 
            // checkBox_mainphase
            // 
            this.checkBox_mainphase.AutoSize = true;
            this.checkBox_mainphase.Location = new System.Drawing.Point(206, 717);
            this.checkBox_mainphase.Name = "checkBox_mainphase";
            this.checkBox_mainphase.Size = new System.Drawing.Size(128, 16);
            this.checkBox_mainphase.TabIndex = 4;
            this.checkBox_mainphase.Text = "주요 구문 들여쓰기";
            this.checkBox_mainphase.UseVisualStyleBackColor = true;
            // 
            // progressBar1
            // 
            this.progressBar1.Location = new System.Drawing.Point(462, 718);
            this.progressBar1.Name = "progressBar1";
            this.progressBar1.Size = new System.Drawing.Size(313, 22);
            this.progressBar1.TabIndex = 5;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1058, 766);
            this.Controls.Add(this.progressBar1);
            this.Controls.Add(this.checkBox_mainphase);
            this.Controls.Add(this.linkLabel1);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.richTextBox_after);
            this.Controls.Add(this.richTextBox_before);
            this.Name = "Form1";
            this.Text = "쿼리문 인덴트 셋팅";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.RichTextBox richTextBox_before;
        private System.Windows.Forms.RichTextBox richTextBox_after;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.LinkLabel linkLabel1;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.CheckBox checkBox_mainphase;
        private System.Windows.Forms.ProgressBar progressBar1;
    }
}

