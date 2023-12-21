#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
#include"HamPhu.cpp"
#include"date.cpp"
#include"MuonSach.cpp"
// So 1.
void ThemSach(vector<Sach> &sachList)
{
	int sls;
    cout << "Nhap so luong sach: ";
    cin >> sls;
    cin.ignore();
    for (int i = 0; i <sls; i++) 
	{
		cout << "Sach thu" << i+1 << " : " << endl;
		Sach temp;
        temp.nhapSach();
        sachList.push_back(temp);
    }
}
// So 2.
void ThemBanDoc(vector<BanDoc> &banDocList, vector<Sach> &sachList, vector<BangQLMuonSach> &muonsachList)
{
	int slb;
	BanDoc temp;
	temp.macdinh();
    cout << "Nhap so luong ban doc: ";
    cin >> slb;
    cin.ignore();
    for (int i = 0; i <slb; i++) 
	{
		cout << "Ban doc thu " << i+1 << " : " << endl;
		temp.tudongtang();
		temp.nhapBanDoc();
        banDocList.push_back(temp);
        BangQLMuonSach l;
        int k;
	    cout<< "Ban co muon muon sach khong(1. co, 2. khong): ";
	    cin>>k; cin.ignore();
	    if(k == 1)
	        {
	        	taokhungchoBDmuonSach();
	        	int stt = 0;
	        	for (int j = 0; j < sachList.size(); j++)
				{
			        cout << setw(20) << left << stt << setw(20) << left << sachList[j].getMaSach() ;
					cout << setw(20) << left << sachList[j].getTenSach() << setw(20) << left << sachList[j].getGia() <<"\n";
					stt++;
			    }
			    int ms;
			    do
				{
				    cout<< "Nhap STT sach muon(-1 de ket thuc): ";
				    cin>>ms;
				    cin.ignore();
				    if ( ms >= 0 && ms < sachList.size())
				    {
				    	l.themMuonSach(sachList[ms], temp);
				    	cout << "Cam on ban da muon sach!\n";
					}
				    else if(ms != -1)
				    {
				    	cout << "So thu tu ban chon khong hop le!\n";
				    	cout << "Moi nhap lai!\n";
					}
	        	}while(ms != -1);
	        	l.NhapNgayMuon();
	        	l.NhapNgayTra();
	        	muonsachList.push_back(l);
			}
		else
			continue;
		
    }
}
// So 3.
void HienThiSach(vector<Sach> sachList)
{
    taokhungchobangsach();
    for (int i = 0; i < sachList.size(); i++) 
	{
        sachList[i].hienThiThongTinSach();
    }
}
// So 4.
void HienThiBanDoc(vector<BanDoc> banDocList)
{
	taokhungchobangbandoc();
    for (int i = 0; i < banDocList.size(); i++) 
	{
        banDocList[i].hienThiThongTinBanDoc();
    }
}
// So 5.
void HienThiBangMuonSach(vector<BangQLMuonSach> &muonsachList)
{
	int stt = 0;
	for(int i = 0; i < muonsachList.size(); i++)
	{
		cout << "So thu tu: " << stt << "\n";
		muonsachList[i].hienThiThongTinMuonSach();
		stt++;
	}
}
// So 6.
void timkiem(vector<BangQLMuonSach> &muonsachList)
{
	string namefind;
	cin.ignore();
	cout << "Nhap ten ban muon tim: "; getline(cin, namefind);
	for (int i = 0; i < muonsachList.size(); i++)
	{
		if (muonsachList[i].getTenBD().getHoTen() == namefind)
		{
			muonsachList[i].hienThiThongTinMuonSach();
		}
	}
}
// So 7.
void xoa(vector<BangQLMuonSach> &muonsachList)
{
	int stt = 0;
	for(int i = 0; i < muonsachList.size(); i++)
	{
		cout << "So thu tu: " << stt;
		muonsachList[i].hienThiThongTinMuonSach();
		stt++;
	}
	string deleName;
	cin.ignore();
	int a;
	cout << "Nhap ten ban muon xoa: "; getline(cin, deleName);
	for (int i = 0; i < muonsachList.size(); i++)
	{
		if (muonsachList[i].getTenBD().getHoTen() == deleName)
		{
			a = i;
		}
	}
	for (int j = a; j < muonsachList.size(); j++)
	{
		muonsachList[j] = muonsachList[j+1];
	}
	int Stt = 0;
	for(int i = 0; i < muonsachList.size(); i++)
	{
		cout << "So thu tu: " << Stt << "\n";
		muonsachList[i].hienThiThongTinMuonSach();
		Stt++;
	}
}
int Sach::nextmaSach = 10000;
int main()
{
	vector<Sach> sachList(0);
	vector<BanDoc> banDocList(0);
	vector<BangQLMuonSach> muonsachList(0);
	
	// Them sach moi
	int n;
	do
	{
		cout << "--------Chon chuc nang---------\n";
		cout << "0. Thoat\n";
		cout << "1. Them sach moi\n";
		cout << "2. Them ban doc\n";
		cout << "3. Hien thi sach\n";
		cout << "4. Hien thi ban doc\n";
		cout << "5. Vui long nhap thong tin vao bang muon sach\n";
		cout << "6. Tim kiem ban doc\n";
		cout << "7. Xoa ban doc\n";
		cout << "Vui long chon chuc nang: ";
		cin >> n;
		switch(n)
		{
			case 1: 
				ThemSach(sachList);
				break;
			case 2:
				ThemBanDoc(banDocList, sachList, muonsachList);
				break;
			case 3:
				HienThiSach(sachList);
				break;
			case 4:
				HienThiBanDoc(banDocList);
				break;
			case 5:
				HienThiBangMuonSach(muonsachList);
				break;
			case 6:
				timkiem(muonsachList);
				break;
			case 7:
				xoa(muonsachList);
				break;
				
		}	
	}while(n!=0);
	system("pause");
    return 0;
}
