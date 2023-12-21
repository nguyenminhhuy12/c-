class BanDoc
{
	private:
		int maBD;
		string HoTen;
		string DiaChi;
		string LoaiBD;
	public:
		void macdinh()
		{
			maBD = 20000;
		}
		void tudongtang()
		{
			maBD++;
		}
		int getMaBD() 
		{ 
			return maBD; 
		}
		void setMaBD(int newMaBD) 
		{
	        this->maBD = newMaBD;
	    }
	    ////
	    string getHoTen() 
		{ 
			return HoTen; 
		}
		void setHoTen(string newHoTen) 
		{
	        this->HoTen = newHoTen;
	    }
	    ////
	    string getDiaChi() 
		{ 
			return DiaChi; 
		}
		void setDiaChi(string newDiaChi) 
		{
	        this->DiaChi = newDiaChi;
	    }
	    ////
	    string getLoaiBD()
		{ 
			return LoaiBD; 
		}
		void setLoaiBD(string newLoaiBD) 
		{
	        this->LoaiBD = newLoaiBD;
		}
		
void nhapBanDoc()
{
	cout << setw(8) << left << " ";
	cout << "Ho va Ten: "; getline(cin, this->HoTen);
	cout << setw(8) << left << " ";
	cout << "Dia chi: "; getline(cin, this->DiaChi);
	cout << setw(8) << left << " ";
	cout << "Loai Ban Doc: "; getline(cin, this->LoaiBD);
}
void hienThiThongTinBanDoc()
{
	cout << setw(20) << left << maBD << setw(20) << left << HoTen;
	cout << setw(20) << left << DiaChi  << setw(20) << left << LoaiBD << "\n";
}	
};

