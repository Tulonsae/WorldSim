In progress - moved comments from header file here.
Need to turn this into real documentation.

/*
 * All calendar arithmetic is done by this library.
 *
 * Calendar days must be positive integers or 0.  Negative numbers are used
 * for unknown, undefined, and so forth (see sim.h).
 *
 * For events before the calendar's 0th day, use a different calendar with
 * a conversion rule.
 *
 * Data is stored in days.  This is defined as Time.  The Time for a day
 * starts with .0 and ends just before the next .0.  For example, the first
 * day (Day 1) is from 0.0 to 0.9_ (repeating).  The next day (Day 2) would
 * be from 1.0 to 1.9_ (repeating).
 *
 * TODO - Separate functions by planetary rules (equinoxes, tropical year,
 * moon phases, etc.) and by calendar events (months, holidays, etc.).
 *
 * TODO - add moon phases.
 *
 * TODO - Setup the ability for various types of calendars, that can be
 * defined in data rules.  Same for planetary rules.
 *
 * Also handle holidays.
 *
 * TODO - implement months for Date structure.
 */
