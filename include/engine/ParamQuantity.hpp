#pragma once
#include <Quantity.hpp>
#include <engine/Param.hpp>


namespace rack {
namespace engine {


struct Module;


/** A Quantity that wraps an engine::Param. */
struct ParamQuantity : Quantity {
	Module* module = NULL;
	int paramId = 0;

	/** The minimum allowed value. */
	float minValue = 0.f;
	/** The maximum allowed value. Must be greater than minValue. */
	float maxValue = 1.f;
	/** The initial value. */
	float defaultValue = 0.f;

	/** The name of the parameter, using sentence capitalization.
	e.g. "Frequency", "Pulse width", "Alternative mode"
	*/
	std::string label;
	/** The numerical unit of measurement appended to the value.
	Unit words and abbreviations should have a space to separate the numerical value from the number (e.g. " semitones", " V", " ms").
	Unit symbols should have no space (e.g. "%", "º").
	*/
	std::string unit;
	/** Set to 0 for linear, positive for exponential, negative for logarithmic. */
	float displayBase = 0.f;
	float displayMultiplier = 1.f;
	float displayOffset = 0.f;
	int displayPrecision = 5;
	/** An optional one-sentence description of the parameter. */
	std::string description;
	/** Enables parameter resetting when the module is reset.
	*/
	bool resetEnabled = true;
	/** Enables parameter randomization when the module is randomized.
	Unbounded (infinite) parameters are not randomizable, regardless of this setting.
	*/
	bool randomizeEnabled = true;

	Param* getParam();
	/** Request to the engine to smoothly set the value */
	void setSmoothValue(float smoothValue);
	float getSmoothValue();

	void setValue(float value) override;
	float getValue() override;
	float getMinValue() override;
	float getMaxValue() override;
	float getDefaultValue() override;
	float getDisplayValue() override;
	void setDisplayValue(float displayValue) override;
	std::string getDisplayValueString() override;
	void setDisplayValueString(std::string s) override;
	int getDisplayPrecision() override;
	std::string getLabel() override;
	std::string getUnit() override;
};


} // namespace engine
} // namespace rack
