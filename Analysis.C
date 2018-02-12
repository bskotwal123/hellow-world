#define Analysis_cxx
#include "Analysis.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <cmath>

static const int max = 10;

using namespace std;
void Analysis::Loop()
{

   if (fChain == 0) return;
   TFile *f = new TFile("jets.root","RECREATE");
   TH1I *EvtHdr__mNVtx_histo = new TH1I (" EvtHdr__mNVtx_histo","No. of vertices",100,0,100);
   TH1I *EvtHdr__mNVtxGood_histo = new TH1I("EvtHdr__mNVtxGood_histos","No. of Good Vertices",100,0,100);
   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
        EvtHdr__mNVtx_histo->Fill(EvtHdr__mNVtx);
        EvtHdr__mNVtxGood_histo->Fill(EvtHdr__mNVtxGood);
   
   
   }
   EvtHdr__mNVtx_histo->Write();
   EvtHdr__mNVtxGood_histo->Write();


   f->Close();

}
