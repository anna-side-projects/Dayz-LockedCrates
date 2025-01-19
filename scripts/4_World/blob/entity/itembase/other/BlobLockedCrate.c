class BlobLockedCrate : Container_Base
{
    bool locked;
    bool open;
    BlobLockedCrate()
    {
        locked = true;
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
}