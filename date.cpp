class date
{
    private:
        string ngay;
        string thang;
        string nam;
    public:
        date()
		{
        	ngay = "";
        	thang = "";
        	nam = "";
		}
		date(int ngay,int thang,int nam)
		{
			this->ngay = ngay;
			this->thang = thang;
			this->nam = nam;
		}
		//
		string GetNgay()
		{
			return this->ngay;
		}
		void SetNgay(int ngay)
		{
			this->ngay = ngay;
		}
		//
		string GetThang()
		{
			return this->thang;
		}
		void SetThang(int thang)
		{
			this->thang = thang;
		}
		//
		string GetNam()
		{
			return this->nam;
		}
		void SetNam(int nam)
		{
			this->nam = nam;
		}
		
		void Nhap()
		{
			string s;
			int i=0;
			cin>>s; cin.ignore();
			do
			{
				this->ngay += s[i];
				i++;
			}while(s[i]!='/');
			i++;
			do
			{
				this->thang += s[i];
				i++;
			}while(s[i]!='/');
			i++;
			do
			{
				this->nam += s[i];
				i++;
			}while(s[i]!='\0');
		}
};
