# Constants and Given Values for OSNR Calculation
amplifier_gain = 15  # in dBm
fiber_attenuation_per_km = 0.2  # in dB/km
total_distance = 1000  # in km
noise_figure = 6  # in dB
amplifier_spacing = 50  # in km
required_margin = 4  # in dB

# Total Fiber Attenuation
total_fiber_attenuation = fiber_attenuation_per_km * total_distance

# Total Gain Required (Taking into account the losses and required margin)
total_gain_required = total_fiber_attenuation + required_margin

# Number of Amplifiers (excluding the first one)
num_amplifiers = total_distance / amplifier_spacing - 1

# OSNR Calculation
# OSNR = (Output Power - Noise Figure) / (Number of Amplifiers)
# Assuming Output Power is equal to the Gain (for simplification)
osnr = amplifier_gain - noise_figure - 10 * log10(num_amplifiers)  # in dB

osnr

