class BlobLockedCrate extends Container_Base
{
    bool isLocked;
    override bool CanReceiveItemIntoCargo(EntityAI item)
    {
        return (!isLocked) & super.CanReceiveItemIntoCargo(item); 
    }

    override void SetActions()
    {
        super.SetActions();
        AddAction(BlobActionUnlockCrate);
        AddAction(BlobActionLockCrate);
    }

    bool IsLocked()
    {
        return isLocked;
    }

    void Lock()
    {
        isLocked = true;
    }
    void Unlock()
    {
        isLocked = false;
    }
}