#include"Sach.cpp"
#include"BanDoc.cpp"
class BangQLMuonSach
{
	private:
		vector<Sach> s;
		BanDoc bd;
		date ngayMuon;
		date ngayTra;
	public:
		
		void themMuonSach(Sach newSach, BanDoc _bd)
		{
			bd = _bd ;
			s.push_back(newSach);
		}
		void setSach(vector<Sach> newSach)
		{
			s = newSach;
		}
		
//		void NhapMuonSach(vector<Sach> a, BanDoc b)
//		{
//			s = a;
//			bd = b;
//		}
		
		BanDoc getTenBD()
		{
			return bd;
		}
		
		void NhapNgayMuon()
		{
		    cout<<"Nhap ngay/thang/nam muon sach(dd/mm/yyyy): ";
		    ngayMuon.Nhap();
		}
		
		void NhapNgayTra()
		{
			cout<<"Nhap ngay/thang/nam tra sach(dd/mm/yyyy): ";
			ngayTra.Nhap();
		}
		
		void hienThiThongTinMuonSach()
		{
			
		    cout << setw(20) << left << bd.getMaBD() << setw(20) << left << bd.getHoTen() << setw(20) << left << bd.getLoaiBD() << endl;
		    cout << "=============================DANH SACH SACH BAN DA MUON===================================";
			cout << endl;
		    for(int i = 0; i < s.size(); i++)
			{
		    	cout << s[i].getMaSach() << setw(10) << left << " " << s[i].getTenSach();
		    	cout << setw(10) << left << " " << ngayMuon.GetNgay() << "/" << ngayMuon.GetThang() << "/" << ngayMuon.GetNam();
		    	cout << setw(10) << left << " " << ngayTra.GetNgay() << "/" << ngayTra.GetThang() << "/" << ngayTra.GetNam() << endl;
			}
			cout << "======================================================================================";
			cout << endl;
		}
};



