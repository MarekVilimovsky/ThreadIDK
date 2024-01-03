
#include <iostream>
#include<Windows.h>

int pintRNDNumber;

DWORD WINAPI RNDGenerator(LPVOID lpParam)
{
    for (;;)
    {
        pintRNDNumber++;
        if (pintRNDNumber > 6) pintRNDNumber = 1;
    }

    return 0;
}

DWORD WINAPI RNDReader(LPVOID lpParam)
{
    
    for (int i=0;i<20;i++)
    {
        
        printf("%i,", pintRNDNumber);
        Sleep(200);
    }
    
    return 0;
}
int main()
{
    DWORD lwdThread1Id;
    DWORD lwdThread2Id;
    HANDLE lhThread2Id;
    //init proměnné
    pintRNDNumber = 1;
    //spuštění RND threadu
    CreateThread(NULL, 0, RNDGenerator, NULL,0,&lwdThread1Id);

    //spuštění čistého threadu
    lhThread2Id=CreateThread(NULL, 0, RNDReader, NULL, 0, &lwdThread2Id);
    WaitForSingleObject(lhThread2Id, 20000);

    std::cout << "Nazdar Svete!\n";
}

// Spuštění programu: Ctrl+F5 nebo nabídka Ladit > Spustit bez ladění
// Ladění programu: F5 nebo nabídka Ladit > Spustit ladění

// Tipy pro zahájení práce:
//   1. K přidání nebo správě souborů použijte okno Průzkumník řešení.
//   2. Pro připojení ke správě zdrojového kódu použijte okno Team Explorer.
//   3. K zobrazení výstupu sestavení a dalších zpráv použijte okno Výstup.
//   4. K zobrazení chyb použijte okno Seznam chyb.
//   5. Pokud chcete vytvořit nové soubory kódu, přejděte na Projekt > Přidat novou položku. Pokud chcete přidat do projektu existující soubory kódu, přejděte na Projekt > Přidat existující položku.
//   6. Pokud budete chtít v budoucnu znovu otevřít tento projekt, přejděte na Soubor > Otevřít > Projekt a vyberte příslušný soubor .sln.
