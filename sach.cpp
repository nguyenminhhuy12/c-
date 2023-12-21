class Sach
{
	private:
		static int nextmaSach;
		int maSach;
		string TenSach;
		string NXB;
		long long Gia;
		int NamXB;
	public:
		Sach()
		{
			maSach = nextmaSach;
			nextmaSach++;
		}
		int getMaSach() 
		{ 
			return maSach; 
		}
	    void setMaSach(int newMaSach) 
		{
	        this->maSach = newMaSach;
	    }
	    ////
	    string getTenSach() 
		{ 
			return TenSach; 
		}
		void setTenSach(string newTenSach) 
		{
	        this->TenSach = newTenSach;
	    }
	    ////
	    string getNXB()  
		{ 
			return NXB; 
		}
		void setNXB(string newNXB) 
		{
	        this->NXB = newNXB;
	    }
	    long long getGia()  
		{ 
			return Gia; 
		}
		void setGia( long long newGia) 
		{
	        if (newGia >= 0) 
			{
	            this->Gia = newGia;
	        } 
			else 
			{
	            cout << "Gia khong hop le.\n";
	        }
	    }
	    int getNamXB()  
		{ 
			return NamXB; 
		}
		void setNamXB(const int newNamXB) 
		{
	        if (newNamXB > 0) 
			{
	            this->NamXB = newNamXB;
	        } 
			else 
			{
	            cout << "Nam khong hop le.\n";
	        }
	    }
	    
void nhapSach()
{
	cout << setw(8) << left << " ";
	cout << "Ten sach: "; getline(cin, TenSach);
	cout << setw(8) << left << " ";
	cout << "Ten nha xuat ban: "; getline(cin, this->NXB);
	cout << setw(8) << left << " ";
	cout << "Gia ban: "; cin >> this-> Gia;
	cout << setw(8) << left << " ";
	cout << "Nam xuat ban: "; cin >> this-> NamXB;	
	cin.ignore();
}
void hienThiThongTinSach()
{
	cout << setw(20) << left << maSach << setw(20) << left << TenSach << setw(20) << left << NXB;
	cout << setw(20) << left << Gia << setw(20) << left << NamXB<<"\n";
}		
};


