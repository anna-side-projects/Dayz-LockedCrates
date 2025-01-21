modded class MissionBase
{
    private string modname = "LockedCrate";
    override void OnInit()
    {
        super.OnInit();
        GetRPCManager().AddRPC(modname, "setOpenRPC", this, SinglePlayerExecutionType.Both);
        GetRPCManager().AddRPC(modname, "setLockedRPC", this, SinglePlayerExecutionType.Both);
    }
}