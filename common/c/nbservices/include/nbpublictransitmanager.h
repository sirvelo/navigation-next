/*
Copyright (c) 2018, TeleCommunication Systems, Inc.
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
   * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the TeleCommunication Systems, Inc., nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE, ARE
DISCLAIMED. IN NO EVENT SHALL TELECOMMUNICATION SYSTEMS, INC.BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*!--------------------------------------------------------------------------

    @file     nbpublictransitmanager.h
*/
/*
    (C) Copyright 2011 by TeleCommunications Systems, Inc.

    The information contained herein is confidential, proprietary
    to TeleCommunication Systems, Inc., and considered a trade secret as
    defined in section 499C of the penal code of the State of
    California. Use of this information by anyone other than
    authorized employees of TeleCommunication Systems, Inc. is granted only
    under a written non-disclosure agreement, expressly
    prescribing the scope and manner of such use.

---------------------------------------------------------------------------*/

#ifndef NBPUBLICTRANSITMANAGER_H
#define NBPUBLICTRANSITMANAGER_H

#include "nbcontext.h"
#include "navpublictypes.h"
#include "nbplace.h"
#include "nbhandler.h"
#include "nbsearchparameters.h"
/*!
    @addtogroup nbpublictransitmanager
    @{
*/
#define NB_PTM_TRANSIT_TIME_LEN             20

// Public Types ..................................................................................
//
typedef struct NB_PublicTransitManager NB_PublicTransitManager;

typedef struct
{
    char            operatingDays[NB_PTM_TRANSIT_TIME_LEN+1];               /*!< The name of operating days,such as weekdays or weekends etc */
    char            startTime[NB_PTM_TRANSIT_TIME_LEN+1];                   /*!< The start time of the service */
    char            endTime[NB_PTM_TRANSIT_TIME_LEN+1];                     /*!< The close time of the service*/
    char            headwaySeconds[NB_PTM_TRANSIT_TIME_LEN+1];              /*!< Headway in seconds */
} NB_PublicTransitHours;

typedef struct
{
    uint32                              stopId;                              /*!< Unique stop agency id */
    uint32                              sequence;                            /*!< Stop sequence*/
    uint32                              agencyId;
    char                                agencyName[NB_PLACE_NAME_LEN+1];     /*!< Name of the transit agency */
    uint32                              routeId;                             /*!< route id for this stop */
    char                                routeShortName[NB_PLACE_NAME_LEN+1]; /*!< Transit route short name */
    char                                routeLongName[NB_PLACE_NAME_LEN+1];  /*!< Transit route long name */
    NB_Category                         routeType;                           /*!< Transit route type */
    nb_color                            routeColor;                          /*!< Transit route color */
    nb_color                            routeTextColor;                      /*!< Transit route text color */
    NB_PublicTransitHours*              hoursOfOperation;                    /*!< Operating hours for this route/stop */
    int                                 hoursOfOperationCount;               /*!< Count of operating hours */
} NB_PublicTransitStop;

typedef struct
{
    uint32                              id;                             /*!< Unique Stop id generated by PTM*/
    NB_PublicTransitStop*                 stops;                        /*!< Array of pointers NB_TransitStops* */
    int                                 countOfStops;                   /*! number of items in stops array*/
    nb_boolean                          isTransitPlaceComplete;         /*!< To verify if the transit place is complete*/
    NB_Place                            place;                          /*!< NB Place*/
    uint32                              stopType;                       /*!< bit flags of all route types for stop */
} NB_PublicTransitPlace;

/*! Public Transit callback function signature

@param status The status of the call
@param places contains pointer to array of places
@param countOfPlaces item count in paces array
@param userData A pointer to opaque user data
*/
typedef void (*NB_PublicTransitRequestCallbackFunction)(NB_RequestStatus status, NB_Error err, uint32* places, uint32 countOfPlaces, void* userData);

/*! Callback function for NB_PublicTransitManagerCreatePlanTrip()

@param err A NB error code associated with the plan trip request
@param startTransitPlaceList An array of transit place ID near the start place, spaces are allocated dynamically.It is the caller's responsibility to free the memory
@param startListCount The count of startTransitPlaceList
@param endTransitPlaceList An array of transit place ID near the end place, spaces are allocated dynamically.It is the caller's responsibility to free the memory
@param endListCount The count of endTransitPlaceList
@param cbData A pointer to opaque user data
*/
typedef void (*NB_PublicTransitPlanTripCallbackFunction)(NB_Error err, uint32* startTransitPlaceList, int startListCount, uint32* endTransitPlaceList, int endListCount, void* cbData);


/*! Defines the request callback to invoke and specifies the user data to be supplied to the callback
*/
typedef struct
{
    NB_PublicTransitRequestCallbackFunction   callback;
    void*                               callbackData;
} NB_PublicTransitRequestCallback;

/*! Public Transit Get Stop Info callback function signature
@param userData A pointer to opaque user data
@param poiner to  Transit place data
*/
typedef void (*NB_PublicTransitGetStopInfoCallbackFunction)(void* userData, NB_PublicTransitPlace* place);

typedef struct
{
    NB_PublicTransitGetStopInfoCallbackFunction callback;
    void* callbackData;
} NB_PublicTransitGetStopInfoCallback;

// Public Functions ..............................................................................

/*! Create a Public Transit Manager instance.

    @returns NB_Error
    @see NB_PublicTransitManagerDestroy
*/
NB_DEC NB_Error
NB_PublicTransitManagerCreate(NB_Context* context,
                              const char* language,
                              NB_PublicTransitManager** instance
                              );

/*! Destroy a PTM instance.

    @returns NB_Error
    @see NB_PublicTransitManagerCreate
*/
NB_DEC NB_Error
NB_PublicTransitManagerDestroy(NB_PublicTransitManager* instance           /*!< public transit manager instance returned by NB_PublicTransitManagerCreate() */
                               );

/*! Request all the stops for all the routes that the provided TransitPlace has.

    @returns NB_Error if failure
*/
NB_DEC NB_Error
NB_PublicTransitManagerRequestStops(NB_PublicTransitManager*   instance, /*!< public transit manager instance returned by NB_PublicTransitManagerCreate() */
                                    uint32                     placeId,  /*!< unique place ID from the TransitPlace in question */
                                    NB_PublicTransitRequestCallback* callback  /*!< callback to be called when operation is complete */
                                    );

/*! Request all the stops for all the routes that the provided TransitPlace has.

    @returns NB_Error if failure
*/
NB_DEC NB_Error
NB_PublicTransitManagerCancelRequests(NB_PublicTransitManager*   instance /*!< public transit manager instance returned by NB_PublicTransitManagerCreate() */
                                    );

/*! Retrieve structure for provided unique TransitPlace ID
this function allocate memory for NB_PublicTransitPlace tree structure
client is responsible to release it using NB_PublicTransitManagerReleaseTransitPlace API
*/
NB_DEC NB_Error
NB_PublicTransitManagerGetStopInfo(NB_PublicTransitManager* instance,  /*!< public transit manager instance returned by NB_PublicTransitManagerCreate() */
                                   uint32                   placeId,   /*!< unique place ID from the TransitPlace in question */
                                   NB_PublicTransitGetStopInfoCallback* callback  /*!< callback to be called when operation is complete */
                                   );

/*! Retrieve NB_PublicTransitPlace structure for provided unique TransitPlace ID
this function allocate memory for NB_PublicTransitPlace tree structure
client is responsible to release it using NB_PublicTransitManagerReleaseTransitPlace API
this is synchronous function
the data stored in NB_PublicTransitPlace may not be complete, client should choose, which function to use NB_PublicTransitManagerGetStopInfo
acyncronious, but always return complete stops data, and this one.
*/
NB_DEC NB_Error
NB_PublicTransitManagerGetCurrentStopInfo(NB_PublicTransitManager* instance,    /*!< public transit manager instance returned by NB_PublicTransitManagerCreate() */
                                       uint32                   placeId,   /*!< unique place ID from the TransitPlace in question */
                                       NB_PublicTransitPlace** place /*!< (out) pointer to NB_PublicTransitPlace */
                                       );


/*! Release NB_PublicTransitStop structure
*/
NB_DEC void
NB_PublicTransitManagerReleaseTransitPlace(NB_PublicTransitPlace* place      /*!< Transit place data pointer */
                                   );

/*! Add public transit stop search result to Public Transit Manager
    @returns NB_Error if no transit stop information provided or other error occurs
*/
NB_DEC NB_Error
NB_PublicTransitManagerAddTransitStop(NB_PublicTransitManager* instance,    /*!< public transit manager instance returned by NB_PublicTransitManagerCreate() */
                                      NB_Place*                place,       /*!< NB_Place data associated with the stop */
                                      NB_PublicTransitPlaceInfo*          transitStop, /*!< TransitStop details for this place */
                                      uint32*                  placeID      /*!< ID for retrieval later (output)*/
                                      );

/*! Nav Plan support.  Take two Places and do two 1st level queries
    @return NB_Error
*/
NB_DEC NB_Error
NB_PublicTransitManagerCreatePlanTrip(NB_PublicTransitManager* instance,    /*!< public transit manager instance returned by NB_PublicTransitManagerCreate() */
                                      NB_Place*                start,       /*!< NB_Place data for the origin of this trip */
                                      NB_Place*                end,         /*!< NB_Place data for the end of this trip */
                                      uint32                   sliceSize,   /*!< Max number of results around each end point to request from server */
                                      NB_PublicTransitPlanTripCallbackFunction callback,  /*!< callback to be called when operation is complete */
                                      void*                    cbData
                                      );

NB_DEC NB_Error
NB_PublicTransitManagerRequestPlanStops(NB_PublicTransitManager* instance,          /*!< public transit manager instance returned by NB_PublicTransitManagerCreate() */
                                        uint32* transitPlaceIds,                    /*!< array of requested place id */
                                        int transitPlaceCount,                      /*!< count of the above array*/
                                        NB_PublicTransitRequestCallback* callback   /*!< callback to be called when operation is complete */
                                        );

NB_DEC NB_Error
NB_PublicTransitManagerRequestTransitOverlayStops(NB_PublicTransitManager* instance,         /*!< public transit manager instance returned by NB_PublicTransitManagerCreate() */
                                                  NB_BoundingBox*          boundingBox,      /*!< bounding box to restrict search for this session */
                                                  const char*              transitTypes[],   /*!< the array of transit type */
                                                  int                      transitTypeCount, /*!< the count of the above array */
                                                  NB_PublicTransitRequestCallback* callback  /*!< callback to be called when operation is complete */
                                                  );

/*! @} */

#endif  // NBPUBLICTRANSITMANAGER_H
