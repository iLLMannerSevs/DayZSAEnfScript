class ActionTurnOnHeadtorch: ActionBase
{
	void ActionTurnOnHeadtorch()
	{
	}
	
	override bool IsInstant()
	{
		return true;
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNonRuined(UAMaxDistances.DEFAULT);
	}
	
	override typename GetInputType()
	{
#ifndef PLATFORM_CONSOLE
		return ToggleLightsActionInput;
#endif
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Headtorch_ColorBase headtorch;
		headtorch = Headtorch_ColorBase.Cast(target.GetObject());
		if ( !headtorch )
			return false;
		
		if ( headtorch.HasEnergyManager() && headtorch.GetCompEM().CanSwitchOn() && headtorch.GetCompEM().CanWork() ) //TODO review conditions for turning off
		{
			return true;
		}
		
		return false;
	}

	override void Start( ActionData action_data )
	{
		super.Start( action_data );
		
		Headtorch_ColorBase headtorch;
		headtorch = Headtorch_ColorBase.Cast(action_data.m_Target.GetObject());
		if ( headtorch.HasEnergyManager() )
		{
			if ( headtorch.GetCompEM().CanWork() )
			{
				headtorch.GetCompEM().SwitchOn();
			}
		}
	}
};
