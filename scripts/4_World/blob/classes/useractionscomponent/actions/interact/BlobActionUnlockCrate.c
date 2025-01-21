class BlobActionUnlockCrate : ActionInteractBase
{
    private string modname = "LockedCrate";
    void BlobActionUnlockCrate()
    {
        m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
        m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
        m_Text = "Unlock";
    }
    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
    {
        Object target_object = target.GetObject();
        if(target_object.IsItemBase())
        {
            BlobLockedCrate crate = BlobLockedCrate.Cast(target_object);
            Crowbar crowbar = Crowbar.Cast(player.GetItemInHands());
            if(crate && crate.IsLocked() && crowbar)
            {
                return true;
            }
        }
        return false;
    }

    override void OnExecuteServer(ActionData action_data)
    {
        Object target_object = action_data.m_Target.GetObject();
        BlobLockedCrate crate = BlobLockedCrate.Cast(target_object);
        if(crate)
        {
            crate.Unlock();
            GetRPCManager().SendRPC(modname, "setLockedRPC", new Param1<bool>(false));
        }
    }
}