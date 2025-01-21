class BlobLockedCrate : Container_Base
{
    bool locked;
    bool open;
    private string modname = "LockedCrate";
    void BlobLockedCrate()
    {
        locked = true;
    }

    override void OnInit()
    {
        GetRPCManager().AddRPC(modname, "setOpenRPC", this, SinglePlayerExecutionType.Both);
        GetRPCManager().AddRPC(modname, "setLockedRPC", this, SinglePlayerExecutionType.Both);
    }

    override bool CanReceiveItemIntoCargo(EntityAI item)
    {
        return IsOpen() & super.CanReceiveItemIntoCargo(item); 
    }
    override bool CanReleaseCargo(EntityAI attachment)
    {
        return !locked & IsOpen();
    }

    override void SetActions()
    {
        super.SetActions();
        AddAction(BlobActionUnlockCrate);
        AddAction(BlobActionLockCrate);
        AddAction(BlobActionOpenCrate);
        AddAction(BlobActionCloseCrate);
    }

    bool IsLocked()
    {
        return locked;
    }

    void Lock()
    {
        locked = true;
        open = false;

    }
    void Unlock()
    {
        locked = false;
    }

    override bool IsOpen()
    {
        return (!locked) & open;
        
    }

    override void Open()
    {
        if(!locked)
            open = true;
    }

    override void Close()
    {
        open = false;
    }

    override bool CanDisplayCargo()
    {
        return IsOpen();
    }

    override bool CanReceiveAttachment(EntityAI attachment, int slotId)
    {
        return super.CanReceiveAttachment(attachment,slotId) & IsOpen();
    }

    void setOpenRPC(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
    {
        Param1<bool> data;

        if(!ctx.Read(data)) return;

        bool toOpen = data.param1;
        if(toOpen)
            Open();
        else
            Close();

        SetSynchDirty();

    }
    void setLockedRPC(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
    {
        Param1<bool> data;
        
        if(!ctx.Read(data)) return;

        bool toLock = data.param1;

        if(lock)
            Lock();
        else
            Unlock();

        SetSynchDirty();

    }






}