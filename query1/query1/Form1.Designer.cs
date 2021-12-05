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
            this.label3 = new System.Windows.Forms.Label();
            this.checkBox_mainphase = new System.Windows.Forms.CheckBox();
            this.progressBar1 = new System.Windows.Forms.ProgressBar();
            this.TOUPPER_checkBox1 = new System.Windows.Forms.CheckBox();
            this.maxcheckBox1 = new System.Windows.Forms.CheckBox();
            this.before_textBox = new System.Windows.Forms.TextBox();
            this.after_textBox = new System.Windows.Forms.TextBox();
            this.textboxtype_comboBox = new System.Windows.Forms.ComboBox();
            this.SuspendLayout();
            // 
            // richTextBox_before
            // 
            this.richTextBox_before.EnableAutoDragDrop = true;
            this.richTextBox_before.ForeColor = System.Drawing.Color.Sienna;
            this.richTextBox_before.ImeMode = System.Windows.Forms.ImeMode.HangulFull;
            this.richTextBox_before.Location = new System.Drawing.Point(26, 33);
            this.richTextBox_before.Name = "richTextBox_before";
            this.richTextBox_before.Size = new System.Drawing.Size(517, 320);
            this.richTextBox_before.TabIndex = 0;
            this.richTextBox_before.Text = "";
            this.richTextBox_before.WordWrap = false;
            // 
            // richTextBox_after
            // 
            this.richTextBox_after.ForeColor = System.Drawing.Color.Black;
            this.richTextBox_after.ImeMode = System.Windows.Forms.ImeMode.HangulFull;
            this.richTextBox_after.Location = new System.Drawing.Point(26, 387);
            this.richTextBox_after.Name = "richTextBox_after";
            this.richTextBox_after.Size = new System.Drawing.Size(517, 320);
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
            this.button1.Text = "시작!";
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
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(915, 745);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(87, 12);
            this.label3.TabIndex = 2;
            this.label3.Text = "made by KCM";
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
            this.progressBar1.Location = new System.Drawing.Point(340, 717);
            this.progressBar1.Name = "progressBar1";
            this.progressBar1.Size = new System.Drawing.Size(313, 22);
            this.progressBar1.TabIndex = 5;
            // 
            // TOUPPER_checkBox1
            // 
            this.TOUPPER_checkBox1.AutoSize = true;
            this.TOUPPER_checkBox1.Location = new System.Drawing.Point(670, 721);
            this.TOUPPER_checkBox1.Name = "TOUPPER_checkBox1";
            this.TOUPPER_checkBox1.Size = new System.Drawing.Size(140, 16);
            this.TOUPPER_checkBox1.TabIndex = 6;
            this.TOUPPER_checkBox1.Text = "모든 글자를 대문자로";
            this.TOUPPER_checkBox1.UseVisualStyleBackColor = true;
            // 
            // maxcheckBox1
            // 
            this.maxcheckBox1.AutoSize = true;
            this.maxcheckBox1.Checked = true;
            this.maxcheckBox1.CheckState = System.Windows.Forms.CheckState.Checked;
            this.maxcheckBox1.Location = new System.Drawing.Point(206, 745);
            this.maxcheckBox1.Name = "maxcheckBox1";
            this.maxcheckBox1.Size = new System.Drawing.Size(79, 16);
            this.maxcheckBox1.TabIndex = 7;
            this.maxcheckBox1.Text = "MAX 압축";
            this.maxcheckBox1.UseVisualStyleBackColor = true;
            // 
            // before_textBox
            // 
            this.before_textBox.ImeMode = System.Windows.Forms.ImeMode.HangulFull;
            this.before_textBox.Location = new System.Drawing.Point(566, 36);
            this.before_textBox.Multiline = true;
            this.before_textBox.Name = "before_textBox";
            this.before_textBox.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.before_textBox.Size = new System.Drawing.Size(470, 316);
            this.before_textBox.TabIndex = 8;
            // 
            // after_textBox
            // 
            this.after_textBox.ImeMode = System.Windows.Forms.ImeMode.HangulFull;
            this.after_textBox.Location = new System.Drawing.Point(566, 387);
            this.after_textBox.Multiline = true;
            this.after_textBox.Name = "after_textBox";
            this.after_textBox.ScrollBars = System.Windows.Forms.ScrollBars.Both;
            this.after_textBox.Size = new System.Drawing.Size(470, 316);
            this.after_textBox.TabIndex = 8;
            // 
            // textboxtype_comboBox
            // 
            this.textboxtype_comboBox.FormattingEnabled = true;
            this.textboxtype_comboBox.Items.AddRange(new object[] {
            "richedit",
            "textbox"});
            this.textboxtype_comboBox.Location = new System.Drawing.Point(340, 745);
            this.textboxtype_comboBox.Name = "textboxtype_comboBox";
            this.textboxtype_comboBox.Size = new System.Drawing.Size(121, 20);
            this.textboxtype_comboBox.TabIndex = 9;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1058, 785);
            this.Controls.Add(this.textboxtype_comboBox);
            this.Controls.Add(this.after_textBox);
            this.Controls.Add(this.before_textBox);
            this.Controls.Add(this.maxcheckBox1);
            this.Controls.Add(this.TOUPPER_checkBox1);
            this.Controls.Add(this.progressBar1);
            this.Controls.Add(this.checkBox_mainphase);
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
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.CheckBox checkBox_mainphase;
        private System.Windows.Forms.ProgressBar progressBar1;
        private System.Windows.Forms.CheckBox TOUPPER_checkBox1;
        private System.Windows.Forms.CheckBox maxcheckBox1;
        private System.Windows.Forms.TextBox before_textBox;
        private System.Windows.Forms.TextBox after_textBox;
        private System.Windows.Forms.ComboBox textboxtype_comboBox;
    }
}

