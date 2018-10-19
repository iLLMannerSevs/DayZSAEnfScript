class ActionStartCarCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.DEFAULT);
	}
};

class ActionStartEngine: ActionContinuousBase
{
	private const float ROUGH_SPECIALTY_WEIGHT = 0.5;

	bool m_BatteryCon = false;
	bool m_SparkCon = false;
	bool m_BeltCon = false;
	bool m_FuelCon = false;
	
	void ActionStartEngine()
	{
		m_CallbackClass = ActionStartCarCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_STARTENGINE;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ALL;
		m_SpecialtyWeight = ROUGH_SPECIALTY_WEIGHT;
		m_LockTargetOnUse = false;
	}

	override void CreateConditionComponents()  
	{	
		m_ConditionTarget = new CCTNone;
		m_ConditionItem = new CCINone;
	}

	override int GetType()
	{
		return AT_VEH_ENGINE_START;
	}
		
	override string GetText()
	{
		return "#start_the_car";
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{	
		HumanCommandVehicle vehCommand = player.GetCommand_Vehicle();
		if( vehCommand )
		{
			Transport trans = vehCommand.GetTransport();

			if ( trans )
			{
				Car car;
				if ( Class.CastTo(car, trans) && !car.IsEngineOn() )
				{
					if ( car.CrewMemberIndex( player ) == DayZPlayerConstants.VEHICLESEAT_DRIVER )
						return true;
				}
			}
		}

		return false;
	}

	override void OnStartServer( ActionData action_data )
	{
		HumanCommandVehicle vehCommand = action_data.m_Player.GetCommand_Vehicle();

		if( vehCommand )
		{
			Transport trans = vehCommand.GetTransport();
			if ( trans )
			{
				CarScript car;
				if ( Class.CastTo(car, trans) )
				{
					m_BatteryCon = false;
					m_SparkCon = false;
					m_BeltCon = false;
					m_FuelCon = false;

					EntityAI item = null;					
					if ( car.IsVitalCarBattery() || car.IsVitalTruckBattery() )
					{
						
						if ( car.IsVitalCarBattery() ) item = car.FindAttachmentBySlotName("CarBattery");
						if ( car.IsVitalTruckBattery() ) item = car.FindAttachmentBySlotName("TruckBattery");
						if ( item && !item.IsRuined() )
							m_BatteryCon = true;
					}
					else
					{
						m_BatteryCon = true;
					}

					item = null;
					if ( car.IsVitalSparkPlug() || car.IsVitalGlowPlug() )
					{
						
						if ( car.IsVitalSparkPlug() ) item = car.FindAttachmentBySlotName("SparkPlug");
						if ( car.IsVitalGlowPlug() ) item = car.FindAttachmentBySlotName("GlowPlug");
						if ( item && !item.IsRuined() )
							m_SparkCon = true;
					}
					else
					{
						m_SparkCon = true;
					}

					//TODO:: make it proper when the belt will be ready
					item = null;
					m_BeltCon = true;
					if ( car.IsVitalEngineBelt()  )
					{
						if ( car.IsVitalGlowPlug() ) item = car.FindAttachmentBySlotName("EngineBelt");
						if ( item && !item.IsRuined() )
							m_BeltCon = true;
					}
					else
					{
						m_BeltCon = true;
					}

					float fuel = car.GetFluidFraction( CarFluid.FUEL );	
					if (  fuel > 0 )
						m_FuelCon = true;
				}
			}
		}
	}
	override void OnCompleteServer( ActionData action_data )
	{
		HumanCommandVehicle vehCommand = action_data.m_Player.GetCommand_Vehicle();
		if( vehCommand )
		{
			Transport trans = vehCommand.GetTransport();
			if ( trans )
			{
				CarScript car;
				if ( Class.CastTo(car, trans) )
				{
					//TODO:: Sounds are not played - waiting for 
					if ( m_FuelCon && m_BeltCon && m_SparkCon && m_BatteryCon )
					{
						car.PlaySound("offroad_engine_start_SoundSet", 5, false);
						car.EngineStart();
					}
					else
					{
						if ( !m_FuelCon )
							car.PlaySound("offroad_engine_failed_start_fuel_SoundSet", 5, false);
							
							// offroad_engine_failed_start_fuel_SoundSet	
							// offroad_engine_failed_start_battery_SoundSet
							// offroad_engine_failed_start_sparkplugs_SoundSet
							
							// offroad_engine_stop_SoundSet
							// offroad_engine_stop_fuel_SoundSet
						
					}
				}
			}
		}
	}
};