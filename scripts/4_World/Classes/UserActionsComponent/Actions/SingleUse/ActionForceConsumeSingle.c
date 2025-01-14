class ActionForceConsumeSingleCB : ActionSingleUseBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CASingleUseQuantityEdible(UAQuantityConsumed.DEFAULT);
	}
};

class ActionForceConsumeSingle: ActionSingleUseBase
{
	const int DEFAULT_CONSUMED_QUANTITY = 1;
	
	void ActionForceConsumeSingle()
	{
		m_CallbackClass = ActionForceConsumeSingleCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INJECTIONTARGET;
		m_StanceMask = DayZPlayerConstants.STANCEIDX_ERECT | DayZPlayerConstants.STANCEIDX_CROUCH;
		m_FullBody = true;
	}
	
	override void CreateConditionComponents()  
	{	
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTMan(UAMaxDistances.DEFAULT);
	}
		
	override string GetText()
	{
		return "#feed";
	}
		
	int GetConsumedQuantity()
	{
		return DEFAULT_CONSUMED_QUANTITY;
	}
	
	override void OnEndServer( ActionData action_data )
	{
		if ( action_data.m_MainItem && action_data.m_MainItem.GetQuantity() <= 0 ) 
		{
			action_data.m_MainItem.SetQuantity(0);
		}
	}
	
	override void OnExecuteServer( ActionData action_data )
	{
		PlayerBase target = PlayerBase.Cast(action_data.m_Target.GetObject());
		
		if ( target && action_data.m_MainItem )
		{
			target.Consume(action_data.m_MainItem, GetConsumedQuantity(), EConsumeType.ITEM_SINGLE_TIME);
		}
	}
};