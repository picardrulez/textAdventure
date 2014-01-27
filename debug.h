using namespace std;
ofstream debugfile;
void debugopen();
void debugclose();
void debugopen()
{
    debugfile.open ("debug.log", ios::out | ios::app);
}

void debugclose()
{
    debugfile.close();
}
