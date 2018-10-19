class ActionUnmountBarbedWireCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.DEFAULT_CONSTRUCT);
	}
};

class ActionUnmountBarbedWire: ActionContinuousBase
{
	float m_DamageAmount;
	string m_SlotName;
	
	void ActionUnmountBarbedWire()
	{
		m_CallbackClass = ActionUnmountBarbedWireCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_CRAFTING;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
		
		m_DamageAmount = 2;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
	}
	
	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNonRuined( UAMaxDistances.BASEBUILDING );
	}

	override int GetType()
	{
		return AT_UNMOUNT_BARBED_WIRE;
	}
		
	override string GetText()
	{
		return "#unmount_barbed_wire";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		Object targetObject = target.GetObject();
		
		if ( targetObject && targetObject.CanUseConstruction() )
		{
			BaseBuildingBase base_building = BaseBuildingBase.Cast( targetObject );
			
			string selection = targetObject.GetActionComponentName( target.GetComponentIndex() );
			
			if ( selection.Length() > 0 )
			{
				int delimiter_index = selection.IndexOfFrom( 0, "_mounted" );
				if ( delimiter_index > -1 )
				{
					selection = selection.Substring( 0, delimiter_index );
					
					BarbedWire barbed_wire = BarbedWire.Cast( base_building.FindAttachmentBySlotName( selection ) );
					if ( barbed_wire && barbed_wire.IsMounted() )
					{
						m_SlotName = selection;
						
						return true;
					}					
				}
			}			
		}
		
		return false;
	}
		
	override void OnCompleteServer( ActionData action_data )
	{	
		BaseBuildingBase base_building = BaseBuildingBase.Cast( action_data.m_Target.GetObject() );
		BarbedWire barbed_wire = BarbedWire.Cast( base_building.FindAttachmentBySlotName( m_SlotName ) );
		
		//unmount
		barbed_wire.SetMountedState( false );
		
		//unlock slot
		int slot_id = barbed_wire.GetInventory().GetSlotId( 0 );
		base_building.GetInventory().SetSlotLock( slot_id, false );
		
		//refresh visuals and physics
		base_building.Refresh();
		
		action_data.m_Player.GetSoftSkillManager().AddSpecialty( m_SpecialtyWeight );
	}
}