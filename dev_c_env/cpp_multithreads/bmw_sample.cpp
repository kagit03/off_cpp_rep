#include<ara/exec/stateclient.cpp>

int main (int argc, char* argv[])
{
	ara::exec::StateClient sc;
	sc.SetState("MachineState", "Restart");
	return 0;
}
