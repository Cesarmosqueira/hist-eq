#include "Display.h"
#include <vector>
using namespace CLRCV;
using namespace System::Threading;
void threadStart()
{

    Application::Run(gcnew Display());
}
[System::STAThread] // This will not work!

int main()
{
    Thread^ t = gcnew Thread(gcnew ThreadStart(threadStart));
    t->ApartmentState = ApartmentState::STA;
    t->Start();
    return 0;
}