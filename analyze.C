/*
*   - data                                Data
*   - stato                               Stato
*   - ricoverati_con_sintomi              RS
*   - terapia_intensiva                   TI 
*   - totale_ospedalizzati                TotOsp
*   - isolamento_domiciliare              ID
*   - totale_attualmente_positivi         Pos
*   - nuovi_attualmente_positivi          NewPos
*   - dimessi_guariti                     Guariti
*   - deceduti                            Deceduti
*   - totale_casi                         Tot
*   - tamponi                             Tamponi
*/

void analyze(){

  TTree *ct = new TTree("ct", "Dati COVID-19 Italia - Andamento Nazionale");

  ct->ReadFile("dataset.csv", "Index/I:Index2/I:Data/I:Stato/C:RS/I:TI:TotOsp:ID:Pos:NewPos:Guariti:Deceduti:Tot:Tamponi", ',');

  // Stampa informazione sul numeor di righe
  cout << endl;
  cout << " Il numero di rigehe letto dal file e': " << ct->GetEntries() << endl;
  cout << endl;
  

  // Dichiarazione  delle variabili per accedere al TTree
  char Stato[5];
  int Data,RS,TI,TotOsp,ID,Pos,NewPos,Guariti,Deceduti,Tot,Tamponi;

  //Associazione tra variabili e nome del TBranch assengato nel TTree
  ct->SetBranchAddress("Data",     &Data);
  ct->SetBranchAddress("RS",       &RS);
  ct->SetBranchAddress("TI",       &TI);
  ct->SetBranchAddress("ID",       &ID);
  ct->SetBranchAddress("TotOsp",   &TotOsp);
  ct->SetBranchAddress("Pos",      &Pos);
  ct->SetBranchAddress("NewPos",   &NewPos);
  ct->SetBranchAddress("Guariti",  &Guariti);
  ct->SetBranchAddress("Deceduti", &Deceduti);
  ct->SetBranchAddress("Tot",      &Tot);
  ct->SetBranchAddress("Tamponi",  &Tamponi);

  int entries = ct->GetEntries();
  for( int i=0; i<entries; i++){

    // Associazione  delle  variabili ai valori corrispondenti alla colonno numero i  
    ct->GetEntry(i);

    // Controllo che i valori siano satti letti correttamente
    cout << std::to_string(Data) << " " << i << " " << Tot << endl;
  }

}
