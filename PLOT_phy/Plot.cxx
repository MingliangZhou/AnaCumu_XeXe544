#include "Plot.h"

const double plot_yMin[] = {   0, -11e-6, -1, 0.4, 0.95,    0};
const double plot_yMax[] = {0.15,  14e-6,  2, 1.0, 1.04, 0.34};

const double graph_leg[6][4] = {
{0.8,   0.68,   0.95,  0.9 },
{0.175, 0.15,  0.975,  0.225},
{0.175, 0.15,  0.975,  0.225},
{0.175, 0.15,  0.975,  0.225},
{0.175, 0.15,  0.975,  0.225},
{0.8,   0.72,   0.95,  0.9}
};

Plot::Plot()
{
	initialize();
	execute();
	finalize();
}

Plot::~Plot()
{
}

void Plot::execute()
{
	cout<<"execute..."<<endl;

	// fix statistical errors in central
	for(int i=0; i<3; i++)
	{
		double x = 0; double y = 0; double yErr = 0;

		sts_c4_1sub[0][0][2][0]->GetPoint(i,x,y);
		yErr = sts_c4_1sub[0][0][2][0]->GetErrorY(i);
		yErr = 1./4*pow(fabs(y),-3./4)*yErr;
		sts_v4_1sub[0][0][2][0]->SetPointError(i,0,yErr);

		sts_c6_1sub[0][0][2][0]->GetPoint(i,x,y);
		yErr = sts_c6_1sub[0][0][2][0]->GetErrorY(i);
		yErr = 1./4/6*pow(fabs(y),-5./6)*yErr;
		sts_v6_1sub[0][0][2][0]->SetPointError(i,0,yErr);

		sts_c4_1sub[0][1][3][0]->GetPoint(i,x,y);
		yErr = sts_c4_1sub[0][1][3][0]->GetErrorY(i);
		yErr = 1./4*pow(fabs(y),-3./4)*yErr;
		sts_v4_1sub[0][1][3][0]->SetPointError(i,0,yErr);
	}

	// Remove Points for paper
	///*
	for(int iV=3; iV<5; iV++)
	{
		for(int i=sts_c4_1sub[0][1][iV][0]->GetN()-1; i>=10; i--)
		{
			// Phase5 ONLY
			sts_c4_1sub[0][1][iV][0]->RemovePoint(i);
			sys_c4_1sub[0][1][iV][0]->RemovePoint(i);
		}
	}
	for(int i=0; i<2; i++)
	{
		//sts_c4_1sub[0][1][3][0]->RemovePoint(0);
		//sys_c4_1sub[0][1][3][0]->RemovePoint(0);
		//sts_v4_1sub[0][1][3][0]->RemovePoint(0);
		//sys_v4_1sub[0][1][3][0]->RemovePoint(0);
	}
	for(int i=sts_c4_1sub[1][0][3][0]->GetN()-1; i>=31; i--)
	{
		sts_c4_1sub[1][0][3][0]->RemovePoint(i);
		sys_c4_1sub[1][0][3][0]->RemovePoint(i);
	}
	for(int i=sts_c4_1sub[1][0][4][0]->GetN()-1; i>=32; i--)
	{
		sts_c4_1sub[1][0][4][0]->RemovePoint(i);
		sys_c4_1sub[1][0][4][0]->RemovePoint(i);
	}
	for(int i=sts_nsc_1sub[0][0][0][0]->GetN()-1; i>=23; i--)
	{
		sts_nsc_1sub[0][0][0][0]->RemovePoint(i);
		sys_nsc_1sub[0][0][0][0]->RemovePoint(i);
	}
	for(int i=sts_nsc_1sub[0][0][1][0]->GetN()-1; i>=23; i--)
	{
		sts_nsc_1sub[0][0][1][0]->RemovePoint(i);
		sys_nsc_1sub[0][0][1][0]->RemovePoint(i);
	}
	for(int i=0; i<=2; i++)
	{
		sts_cr42_1sub[0][0][2][0]->RemovePoint(0);
		sys_cr42_1sub[0][0][2][0]->RemovePoint(0);
	}
	for(int i=sts_cr64_1sub[0][0][2][0]->GetN()-1; i>=21; i--)
	{
		sts_cr64_1sub[0][0][2][0]->RemovePoint(i);
		sys_cr64_1sub[0][0][2][0]->RemovePoint(i);
	}
	for(int i=0; i<10; i++)
	{
		sts_cr64_1sub[0][0][2][0]->RemovePoint(0);
		sys_cr64_1sub[0][0][2][0]->RemovePoint(0);
	}
	
	for(int i=sts_cr64_1sub[1][0][2][0]->GetN()-1; i>=23; i--)
	{
		//sts_cr64_1sub[1][0][2][0]->RemovePoint(i);
		//sys_cr64_1sub[1][0][2][0]->RemovePoint(i);
	}
	for(int i=0; i<5; i++)
	{
		//sts_cr64_1sub[1][0][2][0]->RemovePoint(0);
		//sys_cr64_1sub[1][0][2][0]->RemovePoint(0);
	}

	for(int i=sts_vd4_1sub[0][0][2][0][0]->GetN()-1; i>=10; i--)
	{
		sts_vd4_1sub[0][0][2][0][0]->RemovePoint(i);
		sys_vd4_1sub[0][0][2][0][0]->RemovePoint(i);
	}
	for(int i=sts_vd4_1sub[0][0][3][0][0]->GetN()-1; i>=8; i--)
	{
		sts_vd4_1sub[0][0][3][0][0]->RemovePoint(i);
		sys_vd4_1sub[0][0][3][0][0]->RemovePoint(i);
	}
	for(int i=sts_vd4_1sub[0][0][3][0][1]->GetN()-1; i>=9; i--)
	{
		sts_vd4_1sub[0][0][3][0][1]->RemovePoint(i);
		sys_vd4_1sub[0][0][3][0][1]->RemovePoint(i);
	}
	for(int i=sts_vd4_1sub[0][0][3][0][2]->GetN()-1; i>=9; i--)
	{
		sts_vd4_1sub[0][0][3][0][2]->RemovePoint(i);
		sys_vd4_1sub[0][0][3][0][2]->RemovePoint(i);
	}
	for(int i=sts_vd4_1sub[0][0][3][0][5]->GetN()-1; i>=0; i--)
	{
		sts_vd4_1sub[0][0][3][0][5]->RemovePoint(i);
		sys_vd4_1sub[0][0][3][0][5]->RemovePoint(i);
	}
	//*/

	TFile* fOut = new TFile("../PLOT/canvas.root","RECREATE");
	fOut->cd();
	vector<TGraphErrors*> vSts;
	vector<TGraphAsymmErrors*> vSys;

	// 0: v{2}, v{4}, v{6}
	for(unsigned int iR=0; iR<1; iR++)
	{
		vSts.push_back(sts_v4_1sub[0][0][2][iR]);
		vSts.push_back(sts_v6_1sub[0][0][2][iR]);
		vSts.push_back(sts_v4_1sub[0][1][3][iR]);
		vSys.push_back(sys_v4_1sub[0][0][2][iR]);
		vSys.push_back(sys_v6_1sub[0][0][2][iR]);
		vSys.push_back(sys_v4_1sub[0][1][3][iR]);
		draw_graph(vSts,vSys,-1,iR,-1,0);
		vSts.clear();
		vSys.clear();
	}


	// 1: SC(2,3), SC(2,4), AC(2,2,4)
	for(unsigned int iR=0; iR<1; iR++)
	{
		vSts.push_back(sts_sc_1sub[0][0][0][iR]);
		vSts.push_back(sts_sc_1sub[0][0][1][iR]);
		vSts.push_back(sts_ac_1sub[0][0][2][iR]);
		vSys.push_back(sys_sc_1sub[0][0][0][iR]);
		vSys.push_back(sys_sc_1sub[0][0][1][iR]);
		vSys.push_back(sys_ac_1sub[0][0][2][iR]);
		draw_graph(vSts,vSys,-1,iR,-1,1);
		vSts.clear();
		vSys.clear();
	}

	// 2: NSC(2,3), NSC(2,4), NAC(2,2,4)
	for(unsigned int iR=0; iR<1; iR++)
	{
		vSts.push_back(sts_nsc_1sub[0][0][0][iR]);
		vSts.push_back(sts_nsc_1sub[0][0][1][iR]);
		vSts.push_back(sts_nac_1sub[0][0][2][iR]);
		vSys.push_back(sys_nsc_1sub[0][0][0][iR]);
		vSys.push_back(sys_nsc_1sub[0][0][1][iR]);
		vSys.push_back(sys_nac_1sub[0][0][2][iR]);
		draw_graph(vSts,vSys,-1,iR,-1,2);
		vSts.clear();
		vSys.clear();
	}
	
	// 3: cr42
	for(unsigned int iV=2; iV<3; iV++)
	{
		for(unsigned int iR=0; iR<1; iR++)
		{
			vSts.push_back(sts_cr42_1sub[0][0][iV][iR]);
			vSys.push_back(sys_cr42_1sub[0][0][iV][iR]);
			draw_graph(vSts,vSys,iV,iR,-1,3);
			vSts.clear();
			vSys.clear();
		}
	}
	
	// 4: cr64
	for(unsigned int iV=2; iV<3; iV++)
	{
		for(unsigned int iR=0; iR<1; iR++)
		{
			vSts.push_back(sts_cr64_1sub[0][0][iV][iR]);
			vSys.push_back(sys_cr64_1sub[0][0][iV][iR]);
			draw_graph(vSts,vSys,iV,iR,-1,4);
			vSts.clear();
			vSys.clear();
		}
	}
	
	// 5: vd2, vd4
	for(unsigned int iR=0; iR<1; iR++)
	{
		for(unsigned int iC=0; iC<nCent; iC++)
		{
			vSts.push_back(sts_vd4_1sub[0][0][2][iR][iC]);
			vSts.push_back(sts_vd4_1sub[0][0][3][iR][iC]);
			vSys.push_back(sys_vd4_1sub[0][0][2][iR][iC]);
			vSys.push_back(sys_vd4_1sub[0][0][3][iR][iC]);
			draw_graph(vSts,vSys,-1,iR,iC,5);
			vSts.clear();
			vSys.clear();
		}
	}

	// 0: c2
	for(unsigned int iV=2; iV<NV; iV++)
	{
		for(unsigned int iR=0; iR<1; iR++)
		{
			for(unsigned int iF=0; iF<2; iF++)
			{
				vSts.push_back(sts_c2_1sub[iF][0][iV][iR]);
				vSys.push_back(sys_c2_1sub[iF][0][iV][iR]);
			}
			draw_graphComp(vSts,vSys,iV,iR,-1,0);
			vSts.clear();
			vSys.clear();
		}
	}

	// 1: c4
	for(unsigned int iV=2; iV<NV; iV++)
	{
		for(unsigned int iR=0; iR<1; iR++)
		{
			for(unsigned int iF=0; iF<2; iF++)
			{
				if(iF==0 && (iV==3 || iV==4))
				{
					vSts.push_back(sts_c4_1sub[iF][1][iV][iR]);
					vSys.push_back(sys_c4_1sub[iF][1][iV][iR]);
				}
				else
				{
					vSts.push_back(sts_c4_1sub[iF][0][iV][iR]);
					vSys.push_back(sys_c4_1sub[iF][0][iV][iR]);
				}
			}
			draw_graphComp(vSts,vSys,iV,iR,-1,1);
			vSts.clear();
			vSys.clear();
		}
	}

	// 2: c6
	for(unsigned int iV=2; iV<3; iV++)
	{
		for(unsigned int iR=0; iR<1; iR++)
		{
			for(unsigned int iF=0; iF<2; iF++)
			{
				vSts.push_back(sts_c6_1sub[iF][0][iV][iR]);
				vSys.push_back(sys_c6_1sub[iF][0][iV][iR]);
			}
			draw_graphComp(vSts,vSys,iV,iR,-1,2);
			vSts.clear();
			vSys.clear();
		}
	}

	// 3: v2
	for(unsigned int iV=2; iV<NV; iV++)
	{
		for(unsigned int iR=0; iR<1; iR++)
		{
			for(unsigned int iF=0; iF<2; iF++)
			{
				vSts.push_back(sts_v2_1sub[iF][0][iV][iR]);
				vSys.push_back(sys_v2_1sub[iF][0][iV][iR]);
			}
			draw_graphComp(vSts,vSys,iV,iR,-1,3);
			vSts.clear();
			vSys.clear();
		}
	}

	// 4: v4
	for(unsigned int iV=2; iV<NV; iV++)
	{
		for(unsigned int iR=0; iR<1; iR++)
		{
			for(unsigned int iF=0; iF<2; iF++)
			{
				if(iF==0 && (iV==3 || iV==4))
				{
					vSts.push_back(sts_v4_1sub[iF][1][iV][iR]);
					vSys.push_back(sys_v4_1sub[iF][1][iV][iR]);
				}
				else
				{
					vSts.push_back(sts_v4_1sub[iF][0][iV][iR]);
					vSys.push_back(sys_v4_1sub[iF][0][iV][iR]);
				}
			}
			draw_graphComp(vSts,vSys,iV,iR,-1,4);
			vSts.clear();
			vSys.clear();
		}
	}

	// 5: v6
	for(unsigned int iV=2; iV<3; iV++)
	{
		for(unsigned int iR=0; iR<1; iR++)
		{
			for(unsigned int iF=0; iF<2; iF++)
			{
				vSts.push_back(sts_v6_1sub[iF][0][iV][iR]);
				vSys.push_back(sys_v6_1sub[iF][0][iV][iR]);
			}
			draw_graphComp(vSts,vSys,iV,iR,-1,5);
			vSts.clear();
			vSys.clear();
		}
	}

	// 6: sc
	for(unsigned int iV=0; iV<2; iV++)
	{
		for(unsigned int iR=0; iR<1; iR++)
		{
			for(unsigned int iF=0; iF<2; iF++)
			{
				vSts.push_back(sts_sc_1sub[iF][0][iV][iR]);
				vSys.push_back(sys_sc_1sub[iF][0][iV][iR]);
			}
			draw_graphComp(vSts,vSys,iV,iR,-1,6);
			vSts.clear();
			vSys.clear();
		}
	}

	// 7: ac
	for(unsigned int iV=2; iV<3; iV++)
	{
		for(unsigned int iR=0; iR<1; iR++)
		{
			for(unsigned int iF=0; iF<2; iF++)
			{
				vSts.push_back(sts_ac_1sub[iF][0][iV][iR]);
				vSys.push_back(sys_ac_1sub[iF][0][iV][iR]);
			}
			draw_graphComp(vSts,vSys,iV,iR,-1,7);
			vSts.clear();
			vSys.clear();
		}
	}

	// 8: nsc
	for(unsigned int iV=0; iV<2; iV++)
	{
		for(unsigned int iR=0; iR<1; iR++)
		{
			for(unsigned int iF=0; iF<2; iF++)
			{
				vSts.push_back(sts_nsc_1sub[iF][0][iV][iR]);
				vSys.push_back(sys_nsc_1sub[iF][0][iV][iR]);
			}
			draw_graphComp(vSts,vSys,iV,iR,-1,8);
			vSts.clear();
			vSys.clear();
		}
	}

	// 9: nac
	for(unsigned int iV=2; iV<3; iV++)
	{
		for(unsigned int iR=0; iR<1; iR++)
		{
			for(unsigned int iF=0; iF<2; iF++)
			{
				vSts.push_back(sts_nac_1sub[iF][0][iV][iR]);
				vSys.push_back(sys_nac_1sub[iF][0][iV][iR]);
			}
			draw_graphComp(vSts,vSys,iV,iR,-1,9);
			vSts.clear();
			vSys.clear();
		}
	}

	// 10: cr42
	for(unsigned int iV=2; iV<3; iV++)
	{
		for(unsigned int iR=0; iR<1; iR++)
		{
			for(unsigned int iF=0; iF<2; iF++)
			{
				vSts.push_back(sts_cr42_1sub[iF][0][iV][iR]);
				vSys.push_back(sys_cr42_1sub[iF][0][iV][iR]);
			}
			draw_graphComp(vSts,vSys,iV,iR,-1,10);
			vSts.clear();
			vSys.clear();
		}
	}

	// 11: cr64
	for(unsigned int iV=2; iV<3; iV++)
	{
		for(unsigned int iR=0; iR<1; iR++)
		{
			for(unsigned int iF=0; iF<2; iF++)
			{
				vSts.push_back(sts_cr64_1sub[iF][0][iV][iR]);
				vSys.push_back(sys_cr64_1sub[iF][0][iV][iR]);
			}
			draw_graphComp(vSts,vSys,iV,iR,-1,11);
			vSts.clear();
			vSys.clear();
		}
	}

	fOut->Close();
}

void Plot::initialize()
{
	cout<<"initialize..."<<endl;

	double x[24] = {0};
	double y[24] = {0};
	for(int i=0; i<24; i++)
	{
		x[i] = (np_cent[i]+np_cent[i+1])/2;
		y[i] = np_np[i];
	}
	gCvt_Cent_Npart = new TGraph(24,x,y);
	gCvt_Cent_Npart->SetName("gCvt_Cent_Npart");

	TFile* fConfPb = new TFile("../INPUT/hist_PbPb502_bin1.root","READ");
	TFile* fCmsPb = new TFile("../INPUT/cms.root","READ");

	TFile* fIn[NF][2];
	for(unsigned int iF=0; iF<2; iF++)
	{
		for(unsigned int iB=0; iB<2; iB++)
		{
			if(iF==0) sprintf(name,"../../MAIN_norm2PC/OUTPUT/Phase5/hist_XeXe544_binCent_bin%d.root",iB); // Phase
			if(iF==1) sprintf(name,"../../MAIN_PbPb502/OUTPUT/Phase5/hist_PbPb502_binCent_bin%d.root",iB); // Phase
			fIn[iF][iB] = new TFile(name,"READ");
			for(unsigned int iV=0; iV<NV; iV++)
			{
				for(unsigned int iR=0; iR<NR; iR++)
				{
					// borrow from other experiments
					if(iF==1)
					{
						sprintf(name,"sys_c4_1sub_Har%d_Pt0",iV); sys_c4_1sub[iF][iB][iV][iR] = (TGraphAsymmErrors*)fConfPb->Get(name);
						sprintf(name,"sys_c4_1sub_Har%d_PtRef%d",iV,iR); sys_c4_1sub[iF][iB][iV][iR]->SetName(name);
						sprintf(name,"sts_c4_1sub_Har%d_Pt0",iV); sts_c4_1sub[iF][iB][iV][iR] = (TGraphErrors*)fConfPb->Get(name);
						sprintf(name,"sts_c4_1sub_Har%d_PtRef%d",iV,iR); sts_c4_1sub[iF][iB][iV][iR]->SetName(name);
						cvt_Npart(gCvt_Cent_Npart,sts_c4_1sub[iF][iB][iV][iR],sys_c4_1sub[iF][iB][iV][iR]); // Phase5

						sprintf(name,"CMS_ratio_v6_v4"); sys_cr64_1sub[iF][iB][iV][iR] = (TGraphAsymmErrors*)fCmsPb->Get(name);
						sprintf(name,"sys_cr64_1sub_Har%d_PtRef%d",iV,iR); sys_cr64_1sub[iF][iB][iV][iR]->SetName(name);
						int NB = sys_cr64_1sub[iF][iB][iV][iR]->GetN();
						double x[NB]; double xErr[NB];
						double y[NB]; double yErr[NB];
						for(int i=0; i<NB; i++)
						{
							sys_cr64_1sub[iF][iB][iV][iR]->GetPoint(i,x[i],y[i]);
							xErr[i] = 0;
							yErr[i] = 0;
						}
						sts_cr64_1sub[iF][iB][iV][iR] = new TGraphErrors(NB,x,y,xErr,yErr);
						sprintf(name,"sts_cr64_1sub_Har%d_PtRef%d",iV,iR); sts_cr64_1sub[iF][iB][iV][iR]->SetName(name);
						cvt_Npart(gCvt_Cent_Npart,sts_cr64_1sub[iF][iB][iV][iR],sys_cr64_1sub[iF][iB][iV][iR]); // Phase5
					}

					readHist_VR(fIn[iF][iB],sys_c2_1sub[iF][iB][iV][iR],"sys_c2_1sub",iV,iR);
					if(iF==0) readHist_VR(fIn[iF][iB],sys_c4_1sub[iF][iB][iV][iR],"sys_c4_1sub",iV,iR);
					readHist_VR(fIn[iF][iB],sys_c6_1sub[iF][iB][iV][iR],"sys_c6_1sub",iV,iR);
					readHist_VR(fIn[iF][iB],sys_nc4_1sub[iF][iB][iV][iR],"sys_nc4_1sub",iV,iR);
					readHist_VR(fIn[iF][iB],sys_nc6_1sub[iF][iB][iV][iR],"sys_nc6_1sub",iV,iR);
					readHist_VR(fIn[iF][iB],sys_v2_1sub[iF][iB][iV][iR],"sys_v2_1sub",iV,iR);
					readHist_VR(fIn[iF][iB],sys_v4_1sub[iF][iB][iV][iR],"sys_v4_1sub",iV,iR);
					readHist_VR(fIn[iF][iB],sys_v6_1sub[iF][iB][iV][iR],"sys_v6_1sub",iV,iR);
					readHist_VR(fIn[iF][iB],sys_cr42_1sub[iF][iB][iV][iR],"sys_cr42_1sub",iV,iR);
					if(iF==0) readHist_VR(fIn[iF][iB],sys_cr64_1sub[iF][iB][iV][iR],"sys_cr64_1sub",iV,iR);
					readHist_VR(fIn[iF][iB],sys_sc_1sub[iF][iB][iV][iR],"sys_sc_1sub",iV,iR);
					readHist_VR(fIn[iF][iB],sys_nsc_1sub[iF][iB][iV][iR],"sys_nsc_1sub",iV,iR);
					readHist_VR(fIn[iF][iB],sys_ac_1sub[iF][iB][iV][iR],"sys_ac_1sub",iV,iR);
					readHist_VR(fIn[iF][iB],sys_nac_1sub[iF][iB][iV][iR],"sys_nac_1sub",iV,iR);
					readHist_VR(fIn[iF][iB],sys_c2_3sub[iF][iB][iV][iR],"sys_c2_3sub",iV,iR);
					readHist_VR(fIn[iF][iB],sys_c4_3sub[iF][iB][iV][iR],"sys_c4_3sub",iV,iR);
					readHist_VR(fIn[iF][iB],sys_v2_3sub[iF][iB][iV][iR],"sys_v2_3sub",iV,iR);
					readHist_VR(fIn[iF][iB],sys_v4_3sub[iF][iB][iV][iR],"sys_v4_3sub",iV,iR);
					readHist_VR(fIn[iF][iB],sys_sc_3sub[iF][iB][iV][iR],"sys_sc_3sub",iV,iR);
					readHist_VR(fIn[iF][iB],sys_nsc_3sub[iF][iB][iV][iR],"sys_nsc_3sub",iV,iR);
					readHist_VR(fIn[iF][iB],sys_ac_3sub[iF][iB][iV][iR],"sys_ac_3sub",iV,iR);
					readHist_VR(fIn[iF][iB],sys_nac_3sub[iF][iB][iV][iR],"sys_nac_3sub",iV,iR);
					for(unsigned int iC=0; iC<nCent; iC++)
					{
						readHist_VRC(fIn[iF][iB],sys_vd2_1sub[iF][iB][iV][iR][iC],"sys_vd2_1sub",iV,iR,iC);
						readHist_VRC(fIn[iF][iB],sys_vd4_1sub[iF][iB][iV][iR][iC],"sys_vd4_1sub",iV,iR,iC);
					}

					readHist_VR(fIn[iF][iB],sts_c2_1sub[iF][iB][iV][iR],"sts_c2_1sub",iV,iR);
					if(iF==0) readHist_VR(fIn[iF][iB],sts_c4_1sub[iF][iB][iV][iR],"sts_c4_1sub",iV,iR);
					readHist_VR(fIn[iF][iB],sts_c6_1sub[iF][iB][iV][iR],"sts_c6_1sub",iV,iR);
					readHist_VR(fIn[iF][iB],sts_nc4_1sub[iF][iB][iV][iR],"sts_nc4_1sub",iV,iR);
					readHist_VR(fIn[iF][iB],sts_nc6_1sub[iF][iB][iV][iR],"sts_nc6_1sub",iV,iR);
					readHist_VR(fIn[iF][iB],sts_v2_1sub[iF][iB][iV][iR],"sts_v2_1sub",iV,iR);
					readHist_VR(fIn[iF][iB],sts_v4_1sub[iF][iB][iV][iR],"sts_v4_1sub",iV,iR);
					readHist_VR(fIn[iF][iB],sts_v6_1sub[iF][iB][iV][iR],"sts_v6_1sub",iV,iR);
					readHist_VR(fIn[iF][iB],sts_cr42_1sub[iF][iB][iV][iR],"sts_cr42_1sub",iV,iR);
					if(iF==0) readHist_VR(fIn[iF][iB],sts_cr64_1sub[iF][iB][iV][iR],"sts_cr64_1sub",iV,iR);
					readHist_VR(fIn[iF][iB],sts_sc_1sub[iF][iB][iV][iR],"sts_sc_1sub",iV,iR);
					readHist_VR(fIn[iF][iB],sts_nsc_1sub[iF][iB][iV][iR],"sts_nsc_1sub",iV,iR);
					readHist_VR(fIn[iF][iB],sts_ac_1sub[iF][iB][iV][iR],"sts_ac_1sub",iV,iR);
					readHist_VR(fIn[iF][iB],sts_nac_1sub[iF][iB][iV][iR],"sts_nac_1sub",iV,iR);
					readHist_VR(fIn[iF][iB],sts_c2_3sub[iF][iB][iV][iR],"sts_c2_3sub",iV,iR);
					readHist_VR(fIn[iF][iB],sts_c4_3sub[iF][iB][iV][iR],"sts_c4_3sub",iV,iR);
					readHist_VR(fIn[iF][iB],sts_v2_3sub[iF][iB][iV][iR],"sts_v2_3sub",iV,iR);
					readHist_VR(fIn[iF][iB],sts_v4_3sub[iF][iB][iV][iR],"sts_v4_3sub",iV,iR);
					readHist_VR(fIn[iF][iB],sts_sc_3sub[iF][iB][iV][iR],"sts_sc_3sub",iV,iR);
					readHist_VR(fIn[iF][iB],sts_nsc_3sub[iF][iB][iV][iR],"sts_nsc_3sub",iV,iR);
					readHist_VR(fIn[iF][iB],sts_ac_3sub[iF][iB][iV][iR],"sts_ac_3sub",iV,iR);
					readHist_VR(fIn[iF][iB],sts_nac_3sub[iF][iB][iV][iR],"sts_nac_3sub",iV,iR);
					for(unsigned int iC=0; iC<nCent; iC++)
					{
						readHist_VRC(fIn[iF][iB],sts_vd2_1sub[iF][iB][iV][iR][iC],"sts_vd2_1sub",iV,iR,iC);
						readHist_VRC(fIn[iF][iB],sts_vd4_1sub[iF][iB][iV][iR][iC],"sts_vd4_1sub",iV,iR,iC);
					}
				}
			}
		}
	}
}

void Plot::finalize()
{
	cout<<"finalize..."<<endl;
}

void Plot::draw_graph(vector<TGraphErrors*> vSts, vector<TGraphAsymmErrors*> vSys, int iV, int iR, int iC, int iOpt)
{
	int NG = vSts.size();
	TGraphErrors* gSts[10];
	TGraphAsymmErrors* gSys[10];
	for(int iG=0; iG<NG; iG++)
	{
		gSts[iG] = (TGraphErrors*)vSts.at(iG)->Clone("gSts");
		styleGraph(gSts[iG],iG);
		gSys[iG] = (TGraphAsymmErrors*)vSys.at(iG)->Clone("gSys");
		styleGraph(gSys[iG],iG);
		gSys[iG]->SetFillColor(fC[iG]);
		//gSys[iG]->SetFillStyle(3001);
		for(int i=0; i<gSys[iG]->GetN(); i++)
		{
			if(iOpt!=5)
			{
				gSys[iG]->SetPointEXhigh(i,1);
				gSys[iG]->SetPointEXlow(i,1);
			}
			if(iOpt==5)
			{
				double yErr = gSts[iG]->GetErrorY(i);
				double xErr = (xPt[i+1]-xPt[i])/2.;
				gSts[iG]->SetPointError(i,xErr,yErr);
				gSys[iG]->SetPointEXhigh(i,xErr/3);
				gSys[iG]->SetPointEXlow(i,xErr/3);
			}
		}
	}

	const double scale = 1./50;
	if(iOpt==1) // fix AC(2,2,4) to put in same plot
	{
		for(int i=0; i<gSts[2]->GetN(); i++)
		{
			double x = 0;
			double y = 0;
			double yErr = 0;
			double yErrUp = 0;
			double yErrLw = 0;

			gSts[2]->GetPoint(i,x,y);
			gSts[2]->SetPoint(i,x,scale*y);
			yErr = gSts[2]->GetErrorY(i);
			gSts[2]->SetPointError(i,0,scale*yErr);

			gSys[2]->GetPoint(i,x,y);
			gSys[2]->SetPoint(i,x,scale*y);
			yErrUp = gSys[2]->GetErrorYhigh(i);
			yErrLw = gSys[2]->GetErrorYlow(i);
			gSys[2]->SetPointEYhigh(i,scale*yErrUp);
			gSys[2]->SetPointEYlow(i,scale*yErrLw);
		}

		for(int i=0; i<gSys[2]->GetN(); i++)
		{
			gSys[2]->SetPointEXhigh(i,1);
			gSys[2]->SetPointEXlow(i,1);
		}
	}

	TLatex* tex = new TLatex();
	tex->SetTextFont(42);
	tex->SetTextSize(0.045);
	tex->SetTextAlign(12);
	tex->SetNDC(1);
	TLine* lin = new TLine();
	lin->SetLineColor(1);
	lin->SetLineStyle(2);
	lin->SetLineWidth(2);
	TLegend* leg = new TLegend(graph_leg[iOpt][0],graph_leg[iOpt][1],graph_leg[iOpt][2],graph_leg[iOpt][3]);
	leg->SetTextSize(0.05);
	leg->SetFillStyle(0);
	leg->SetBorderSize(0);
	leg->SetTextFont(42);
	if(iOpt==0 || iOpt==5) leg->SetNColumns(1);
	else leg->SetNColumns(3);
	if(iOpt==0)
	{
		sprintf(name,"v_{%d}{4}",2);
		leg->AddEntry(gSys[0],name,"lpfe");
		sprintf(name,"v_{%d}{6}",2);
		leg->AddEntry(gSys[1],name,"lpfe");
		sprintf(name,"v_{%d}{4}",3);
		leg->AddEntry(gSys[2],name,"lpfe");
	}
	if(iOpt==1)
	{
		leg->AddEntry(gSys[0],"sc_{2,3}{4}","lpfe");
		leg->AddEntry(gSys[1],"sc_{2,4}{4}","lpfe");
		leg->AddEntry(gSys[2],"ac_{2,4}{3}/50","lpfe");
	}
	if(iOpt==2)
	{
		leg->AddEntry(gSys[0],"nsc_{2,3}{4}","lpfe");
		leg->AddEntry(gSys[1],"nsc_{2,4}{4}","lpfe");
		leg->AddEntry(gSys[2],"nac_{2,4}{3}","lpfe");
	}
	if(iOpt==5)
	{
		sprintf(name,"n=%d",2);
		leg->AddEntry(gSys[0],name,"lpfe");
		sprintf(name,"n=%d",3);
		leg->AddEntry(gSys[1],name,"lpfe");
	}

	double xMin =  0;
	double xMax = 80;
	double yMin =  1;
	double yMax = -1;
	if(iOpt==5)
	{
		xMin = 0.5;
		xMax = 20;
	}
	for(int iG=0; iG<NG; iG++) getYrange(gSts[iG],yMin,yMax,iOpt);
	double diff = yMax-yMin;
	yMax += 0.5*diff;
	yMin -= 0.5*diff;
	if(iOpt==0 || iOpt==5) // special for v_n
	{
		yMax = -1;
		yMin = 1;
		for(int iG=0; iG<NG; iG++) getYrange(gSts[iG],yMin,yMax,iOpt);
		yMin = 0;
		yMax += 0.4*(yMax-yMin);
	}

	TH1D* hAxis = new TH1D("hAxis","",1000,xMin,xMax);
	for(int i=0; i<1000; i++) hAxis->SetBinContent(i+1,1E9);
	styleGraph(hAxis,0);

	TCanvas* cOut = new TCanvas("cOut","",400,400);
	gStyle->SetOptStat(0);
	gStyle->SetErrorX(0.0001);
	cOut->cd();
	if(iOpt==5) gPad->SetLogx(1);
	gPad->SetTicks(1,1);
	gPad->SetTopMargin(0.075);
	gPad->SetBottomMargin(0.125);
	gPad->SetLeftMargin(0.15);
	gPad->SetRightMargin(0.025);
	if(iOpt==5)
	{
		hAxis->GetXaxis()->SetMoreLogLabels();
		hAxis->GetXaxis()->SetNoExponent();
	}
	if(iOpt!=5) hAxis->GetXaxis()->SetTitle("Centrality [%]");
	if(iOpt==5) hAxis->GetXaxis()->SetTitle("p_{T} [GeV]");
	hAxis->GetXaxis()->SetTitleOffset(1.15);
	hAxis->GetXaxis()->SetRangeUser(xMin,xMax);
	if(iOpt==0) sprintf(name,"v_{n}{2k}");
	if(iOpt==1) sprintf(name,"Correlator");
	if(iOpt==2) sprintf(name,"Correlator");
	if(iOpt==3) sprintf(name,"v_{%d}{4} / v_{%d}{2PC}",iV,iV);
	if(iOpt==4) sprintf(name,"v_{%d}{6} / v_{%d}{4}",iV,iV);
	if(iOpt==5) sprintf(name,"v_{n}{4}");
	hAxis->GetYaxis()->SetTitle(name);
	hAxis->GetYaxis()->SetTitleOffset(1.6);
	hAxis->GetYaxis()->SetRangeUser(yMin,yMax);
	//hAxis->GetYaxis()->SetRangeUser(plot_yMin[iOpt],plot_yMax[iOpt]);
	//if(iV==3) hAxis->GetYaxis()->SetRangeUser(plot_yMin[iOpt]/2,plot_yMax[iOpt]/2);
	if(iOpt==4) hAxis->GetYaxis()->SetRangeUser(0.95,1.03);
	if(iOpt==5) hAxis->GetYaxis()->SetRangeUser(0,0.22);
	hAxis->Draw();
	for(int iG=0; iG<NG; iG++) gSys[iG]->Draw("2");
	for(int iG=0; iG<NG; iG++) gSts[iG]->Draw("P");
	tex->DrawLatex(0.175,0.875,"#font[72]{ATLAS} #font[42]{Internal}");
	tex->DrawLatex(0.175,0.82,"#font[42]{Xe+Xe #sqrt{#it{s}_{NN}}=5.44 TeV, 3 #mub^{-1}}");
	if(iOpt!=5) sprintf(name,"#font[42]{%.1f<p_{T}<%.1f GeV}",minPtRef[iR],maxPtRef[iR]);
	if(iOpt==5) sprintf(name,"#font[42]{%.1f<p_{T}<%.1f GeV   (%d-%d)%%}",minPtRef[iR],maxPtRef[iR],int(xCent[iC]),int(xCent[iC+1]));
	tex->DrawLatex(0.175,0.76,name);
	if(yMax>0 && yMin<0) lin->DrawLine(xMin,0,xMax,0);
	if(iOpt==4) lin->DrawLine(xMin,1,xMax,1);
	leg->Draw();

	if(iOpt==0) sprintf(name,"../PLOT/v_PtRef%d.pdf",iR);
	if(iOpt==1) sprintf(name,"../PLOT/sc_PtRef%d.pdf",iR);
	if(iOpt==2) sprintf(name,"../PLOT/nsc_PtRef%d.pdf",iR);
	if(iOpt==3) sprintf(name,"../PLOT/cr42_Har%d_PtRef%d.pdf",iV,iR);
	if(iOpt==4) sprintf(name,"../PLOT/cr64_Har%d_PtRef%d.pdf",iV,iR);
	if(iOpt==5) sprintf(name,"../PLOT/vd_PtRef%d_Cent%d.pdf",iR,iC);
	cOut->Print(name);
	if(iOpt==0) sprintf(name,"v_Har%d_PtRef%d",iV,iR);
	if(iOpt==1) sprintf(name,"sc_PtRef%d",iR);
	if(iOpt==2) sprintf(name,"nsc_PtRef%d",iR);
	if(iOpt==3) sprintf(name,"cr42_Har%d_PtRef%d",iV,iR);
	if(iOpt==4) sprintf(name,"cr64_Har%d_PtRef%d",iV,iR);
	if(iOpt==5) sprintf(name,"vd_PtRef%d_Cent%d",iR,iC);
	cOut->SetName(name);
	cOut->Write();

	delete hAxis;
	delete cOut;
}

void Plot::draw_graphComp(vector<TGraphErrors*> vSts, vector<TGraphAsymmErrors*> vSys, int iV, int iR, int iC, int iOpt)
{
	int NG = vSts.size();
	TGraphErrors* gSts[10];
	TGraphAsymmErrors* gSys[10];
	for(int iG=0; iG<NG; iG++)
	{
		gSts[iG] = (TGraphErrors*)vSts.at(iG)->Clone("gSts");
		styleGraph(gSts[iG],iG);
		gSys[iG] = (TGraphAsymmErrors*)vSys.at(iG)->Clone("gSys");
		styleGraph(gSys[iG],iG);
		gSys[iG]->SetFillColor(fC[iG]);
		//gSys[iG]->SetFillStyle(3001);
		for(int i=0; i<gSys[iG]->GetN(); i++)
		{
		/*
			gSys[iG]->SetPointEXhigh(i,1); // Phase4
			gSys[iG]->SetPointEXlow(i,1); // Phase4
		*/
		///*
			gSys[iG]->SetPointEXhigh(i,5); // Phase5
			gSys[iG]->SetPointEXlow(i,5); // Phase5
		//*/
		}
	}

	TLatex* tex = new TLatex();
	tex->SetTextFont(42);
	tex->SetTextSize(0.045);
	tex->SetTextAlign(12);
	tex->SetNDC(1);
	TLine* lin = new TLine();
	lin->SetLineColor(1);
	lin->SetLineStyle(2);
	lin->SetLineWidth(2);
	TLegend* leg = new TLegend(0.75,   0.72,   0.95,  0.9);
	leg->SetTextSize(0.05);
	leg->SetFillStyle(0);
	leg->SetBorderSize(0);
	leg->SetTextFont(42);
	leg->SetNColumns(1);
	leg->AddEntry(gSys[0],"Xe+Xe","lpfe");
	leg->AddEntry(gSys[1],"Pb+Pb","lpfe");

	double xMin =  0;
	//double xMax = 80; // Phase4
	double xMax = 405; // Phase5
	double yMin =  1;
	double yMax = -1;
	for(int iG=0; iG<NG; iG++) getYrange(gSts[iG],yMin,yMax,0);
	double diff = yMax-yMin;
	yMax += 0.7*diff;
	yMin -= 0.3*diff;

	TH1D* hAxis = new TH1D("hAxis","",1000,xMin,xMax);
	for(int i=0; i<1000; i++) hAxis->SetBinContent(i+1,1E9);
	styleGraph(hAxis,0);

	TCanvas* cOut = new TCanvas("cOut","",400,400);
	gStyle->SetOptStat(0);
	gStyle->SetErrorX(0.0001);
	cOut->cd();
	gPad->SetTicks(1,1);
	gPad->SetTopMargin(0.075);
	gPad->SetBottomMargin(0.125);
	gPad->SetLeftMargin(0.15);
	gPad->SetRightMargin(0.025);
	//hAxis->GetXaxis()->SetTitle("Centrality [%]"); // Phase4
	hAxis->GetXaxis()->SetTitle("#LTN_{part}#GT"); // Phase5
	hAxis->GetXaxis()->SetTitleOffset(1.12);
	hAxis->GetXaxis()->SetRangeUser(xMin,xMax);
	if(iOpt==0) sprintf(name,"c_{%d}{2}",iV);
	if(iOpt==1) sprintf(name,"c_{%d}{4}",iV);
	if(iOpt==2) sprintf(name,"c_{%d}{6}",iV);
	if(iOpt==3) sprintf(name,"v_{%d}{2}",iV);
	if(iOpt==4) sprintf(name,"v_{%d}{4}",iV);
	if(iOpt==5) sprintf(name,"v_{%d}{6}",iV);
	if(iOpt==6)
	{
		if(iV==0) sprintf(name,"sc_{2,3}{4}");
		if(iV==1) sprintf(name,"sc_{2,4}{4}");
	}
	if(iOpt==7) sprintf(name,"ac_{2,4}{3}");
	if(iOpt==8)
	{
		if(iV==0) sprintf(name,"nsc_{2,3}{4}");
		if(iV==1) sprintf(name,"nsc_{2,4}{4}");
	}
	if(iOpt==9) sprintf(name,"nac_{2,4}{3}");
	if(iOpt==10) sprintf(name,"v_{%d}{4} / v_{%d}{2PC}",iV,iV);
	if(iOpt==11) sprintf(name,"v_{%d}{6} / v_{%d}{4}",iV,iV);
	hAxis->GetYaxis()->SetTitle(name);
	hAxis->GetYaxis()->SetTitleOffset(1.6);
	hAxis->GetYaxis()->SetRangeUser(yMin,yMax);
	if(iOpt==10) hAxis->GetYaxis()->SetRangeUser(0.4,1.2);
	if(iOpt==11) hAxis->GetYaxis()->SetRangeUser(0.95,1.03);
	hAxis->Draw();
	for(int iG=0; iG<NG; iG++) gSys[iG]->Draw("2");
	for(int iG=0; iG<NG; iG++) gSts[iG]->Draw("P");
	tex->DrawLatex(0.175,0.875,"#font[72]{ATLAS} #font[42]{Internal}");
	tex->DrawLatex(0.175,0.82,"#font[42]{Xe+Xe #sqrt{#it{s}_{NN}}=5.44 TeV, 3 #mub^{-1}}");
	if(iOpt==11) tex->DrawLatex(0.175,0.76,"#font[42]{Pb+Pb #sqrt{#it{s}_{NN}}=5.02 TeV, CMS}");
	else tex->DrawLatex(0.175,0.76,"#font[42]{Pb+Pb #sqrt{#it{s}_{NN}}=5.02 TeV, 22 #mub^{-1}}");
	sprintf(name,"#font[42]{%.1f<p_{T}<%.1f GeV}",minPtRef[iR],maxPtRef[iR]);
	tex->DrawLatex(0.175,0.695,name);
	if(yMax>0 && yMin<0) lin->DrawLine(xMin,0,xMax,0);
	if(iOpt==11) lin->DrawLine(xMin,1,xMax,1);
	leg->Draw();

	if(iOpt==0) sprintf(name,"../PLOT/comp_c2_Har%d_PtRef%d.pdf",iV,iR);
	if(iOpt==1) sprintf(name,"../PLOT/comp_c4_Har%d_PtRef%d.pdf",iV,iR);
	if(iOpt==2) sprintf(name,"../PLOT/comp_c6_Har%d_PtRef%d.pdf",iV,iR);
	if(iOpt==3) sprintf(name,"../PLOT/comp_v2_Har%d_PtRef%d.pdf",iV,iR);
	if(iOpt==4) sprintf(name,"../PLOT/comp_v4_Har%d_PtRef%d.pdf",iV,iR);
	if(iOpt==5) sprintf(name,"../PLOT/comp_v6_Har%d_PtRef%d.pdf",iV,iR);
	if(iOpt==6) sprintf(name,"../PLOT/comp_sc_Har%d_PtRef%d.pdf",iV,iR);
	if(iOpt==7) sprintf(name,"../PLOT/comp_ac_Har%d_PtRef%d.pdf",iV,iR);
	if(iOpt==8) sprintf(name,"../PLOT/comp_nsc_Har%d_PtRef%d.pdf",iV,iR);
	if(iOpt==9) sprintf(name,"../PLOT/comp_nac_Har%d_PtRef%d.pdf",iV,iR);
	if(iOpt==10) sprintf(name,"../PLOT/comp_cr42_Har%d_PtRef%d.pdf",iV,iR);
	if(iOpt==11) sprintf(name,"../PLOT/comp_cr64_Har%d_PtRef%d.pdf",iV,iR);
	cOut->Print(name);
	if(iOpt==0) sprintf(name,"comp_c2_Har%d_PtRef%d",iV,iR);
	if(iOpt==1) sprintf(name,"comp_c4_Har%d_PtRef%d",iV,iR);
	if(iOpt==2) sprintf(name,"comp_c6_Har%d_PtRef%d",iV,iR);
	if(iOpt==3) sprintf(name,"comp_v2_Har%d_PtRef%d",iV,iR);
	if(iOpt==4) sprintf(name,"comp_v4_Har%d_PtRef%d",iV,iR);
	if(iOpt==5) sprintf(name,"comp_v6_Har%d_PtRef%d",iV,iR);
	if(iOpt==6) sprintf(name,"comp_sc_Har%d_PtRef%d",iV,iR);
	if(iOpt==7) sprintf(name,"comp_ac_Har%d_PtRef%d",iV,iR);
	if(iOpt==8) sprintf(name,"comp_nsc_Har%d_PtRef%d",iV,iR);
	if(iOpt==9) sprintf(name,"comp_nac_Har%d_PtRef%d",iV,iR);
	if(iOpt==10) sprintf(name,"comp_cr42_Har%d_PtRef%d",iV,iR);
	if(iOpt==11) sprintf(name,"comp_cr64_Har%d_PtRef%d",iV,iR);
	cOut->SetName(name);
	cOut->Write();

	delete hAxis;
	delete cOut;
}


void Plot::styleGraph(TGraph* hIn, int k)
{
	hIn->SetTitle("");
	hIn->GetYaxis()->SetNdivisions(505);
	hIn->GetYaxis()->SetTitleOffset(1.);    hIn->GetXaxis()->SetTitleOffset(1.);
	hIn->GetYaxis()->SetTitleFont(43);      hIn->GetYaxis()->SetTitleSize(15);
	hIn->GetYaxis()->SetLabelFont(43);      hIn->GetYaxis()->SetLabelSize(15);
	hIn->GetXaxis()->SetTitleFont(43);      hIn->GetXaxis()->SetTitleSize(15);
	hIn->GetXaxis()->SetLabelFont(43);      hIn->GetXaxis()->SetLabelSize(15);
	hIn->SetMarkerStyle(mS[k]);
	hIn->SetMarkerColor(mC[k]);
	hIn->SetLineStyle(lS[k]);
	hIn->SetLineColor(lC[k]);
	hIn->SetLineWidth(2);
}

void Plot::styleGraph(TH1D* hIn, int k)
{
	hIn->SetTitle("");
	hIn->GetYaxis()->SetTitleOffset(1.);    hIn->GetXaxis()->SetTitleOffset(1.);
	hIn->GetYaxis()->SetTitleFont(43);      hIn->GetYaxis()->SetTitleSize(18);
	hIn->GetYaxis()->SetLabelFont(43);      hIn->GetYaxis()->SetLabelSize(18);
	hIn->GetXaxis()->SetTitleFont(43);      hIn->GetXaxis()->SetTitleSize(18);
	hIn->GetXaxis()->SetLabelFont(43);      hIn->GetXaxis()->SetLabelSize(18);
	hIn->SetMarkerStyle(mS[k]);
	hIn->SetMarkerColor(mC[k]);
	hIn->SetLineStyle(lS[k]);
	hIn->SetLineColor(lC[k]);
	hIn->SetLineWidth(2);
}

void Plot::getYrange(TGraph* hIn, double& yMin, double& yMax, int iOpt)
{
	double x; double y;
	for(int i=0; i<hIn->GetN(); i++)
	{
		hIn->GetPoint(i,x,y);
		//if(iOpt!=5 && x>60) continue; // Phase4
		if(iOpt!=5 && x<30) continue; // Phase5
		else if(iOpt==5 && x>10) continue;
		if(y<yMin) yMin = y;
		if(y>yMax) yMax = y;
	}
}

void Plot::cvt_Npart(TGraph* gCvt, TGraphErrors* gSts, TGraphAsymmErrors* gSys)
{
	int NB = gSts->GetN();
	for(int iB=0; iB<NB; iB++)
	{
		double x=0;
		double y=0;
		gSts->GetPoint(iB,x,y);
		x = gCvt->Eval(x);
		gSts->SetPoint(iB,x,y);
		gSys->SetPoint(iB,x,y);
	}
}

void Plot::readHist_VR(TFile* fIn, TGraphErrors*& hIn, const char* hName, int iV, int iR)
{
	sprintf(name,"%s_Har%d_PtRef%d",hName,iV,iR);
	hIn = (TGraphErrors*)fIn->Get(name);
}

void Plot::readHist_VR(TFile* fIn, TGraphAsymmErrors*& hIn, const char* hName, int iV, int iR)
{
	sprintf(name,"%s_Har%d_PtRef%d",hName,iV,iR);
	hIn = (TGraphAsymmErrors*)fIn->Get(name);
}

void Plot::readHist_VRC(TFile* fIn, TGraphErrors*& hIn, const char* hName, int iV, int iR, int iC)
{
	sprintf(name,"%s_Har%d_PtRef%d_Cent%d",hName,iV,iR,iC);
	hIn = (TGraphErrors*)fIn->Get(name);
}

void Plot::readHist_VRC(TFile* fIn, TGraphAsymmErrors*& hIn, const char* hName, int iV, int iR, int iC)
{
	sprintf(name,"%s_Har%d_PtRef%d_Cent%d",hName,iV,iR,iC);
	hIn = (TGraphAsymmErrors*)fIn->Get(name);
}




