modded class ActionConstructor
{
    override void RegisterActions(TTypenameArray actions)
    {
        super.RegisterActions(actions);
        actions.Insert(BlobActionLockCrate);
        actions.Insert(BlobActionUnlockCrate);
        actions.Insert(BlobActionOpenCrate);
        actions.Insert(BlobActionCloseCrate);
    }
};