
class BlobActionCloseCrate : ActionInteractBase
{
    private string modname = "LockedCrate";
    void BlobActionCloseCrate()
    {
        m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
        m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
        m_Text = "Close";
    }
    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
    {
        Object target_object = target.GetObject();
        if(target_object.IsItemBase())
        {
            BlobLockedCrate crate = BlobLockedCrate.Cast(target_object);
            if(crate && !crate.IsLocked() && crate.IsOpen())
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
            crate.Close();
            GetRPCManager().SendRPC(modname, "setOpenRPC", new Param1<bool>(false));
        }
    }
}