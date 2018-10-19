class ActionTakeItemToHands: ActionInteractBase
{
	string m_ItemName = "";
	bool m_ProneException;

	void ActionTakeItemToHands()
	{
		m_MessageSuccess    = "";
		m_CommandUID        = DayZPlayerConstants.CMD_ACTIONMOD_PICKUP_HANDS;
		m_CommandUIDProne	= DayZPlayerConstants.CMD_ACTIONFB_PICKUP_HANDS;
		m_HUDCursorIcon     = CursorIcons.LootCorpse;
	}

	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTObject(UAMaxDistances.DEFAULT);
	}	
	
	override bool HasProneException()
	{
		return m_ProneException;
	}
	
	override int GetType()
	{
		return AT_TAKE_ITEM_TO_HANDS;
	}

	override string GetText()
	{
		return "#take_to_hands";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		ItemBase tgt_item = ItemBase.Cast( target.GetObject() );
		if ( tgt_item && !tgt_item.IsTakeable() ) return false;
		if ( tgt_item && tgt_item.IsBeingPlaced() ) return false;
		
		if ( player.GetCommand_Vehicle() )
			return false;
		
		EntityAI tgt_parent = EntityAI.Cast( target.GetParent() );
		EntityAI tgt_entity = EntityAI.Cast( target.GetObject() );

		if ( tgt_entity && !tgt_parent )
		{
			if ( tgt_entity && tgt_entity.IsItemBase() && !player.GetInventory().CanAddEntityIntoInventory(tgt_entity) && player.GetInventory().CanAddEntityIntoHands(tgt_entity) && tgt_entity.GetHierarchyRootPlayer() != player )
			{
				return true;
			}
		}
		return false;
	}
	
	override bool CanContinue( ActionData action_data )
	{
		return true;
	}
	
	override void OnStartServer( ActionData action_data )
	{
		CheckForHeavyAnimation( action_data );
		
		vector rotation = vector.Zero;
		vector target_dir = action_data.m_Target.GetObject().GetPosition() - action_data.m_Player.GetPosition();
		
		rotation[0] = Math.Atan2(target_dir[0], target_dir[2]) * Math.RAD2DEG;
		action_data.m_Player.SetOrientation(rotation);
	}
	
	override void OnStartClient( ActionData action_data )
	{
		CheckForHeavyAnimation( action_data );
	}
	
	override void OnExecuteServer( ActionData action_data )
	{
		if (!GetGame().IsMultiplayer())
		{
			ActionManagerClient am = ActionManagerClient.Cast(action_data.m_Player.GetActionManager());
			am.UnlockInventory(action_data);
		}
		
		EntityAI ntarget = EntityAI.Cast(action_data.m_Target.GetObject());
		action_data.m_Player.PredictiveTakeEntityToHands(ntarget);
	}
	
	override void OnExecuteClient( ActionData action_data )
	{
		ActionManagerClient am = ActionManagerClient.Cast(action_data.m_Player.GetActionManager());
		am.UnlockInventory(action_data);

		EntityAI ntarget = EntityAI.Cast(action_data.m_Target.GetObject());
		action_data.m_Player.PredictiveTakeEntityToHands(ntarget);
	}
	
	void CheckForHeavyAnimation( ActionData action_data )
	{
		m_ProneException = true;
		Object target = action_data.m_Target.GetObject();
		
		if (target && target.ConfigIsExisting("heavyItem"))
		{
			if (target.ConfigGetBool("heavyItem"))
			{
				m_ProneException = false;
				m_FullBody = true;
				m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_PICKUP_HEAVY;
			}
			else
				m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_PICKUP_HANDS;
		}
		
	}
};