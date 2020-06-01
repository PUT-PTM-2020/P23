using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using PTM.Services;

namespace PTM.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class DeviceController : ControllerBase
    {
        private readonly AppStateService _appStateService;
        public DeviceController(AppStateService appStateService)
        {
            _appStateService = appStateService;
        }

        [HttpGet("setDisplay/{deviceId}/{display}/{cardId}")]
        public void SetDisplay(string deviceId, string display, string cardId)
        {
            _appStateService.OnDisplayChange(deviceId, display, cardId);
            return;
        }

        [HttpGet("sendKey/{deviceId}/{key}")]
        public void SendKey(string deviceId, string key)
        {
            _appStateService.OnKeyPress(deviceId, key);
            return;
        }

        /// <summary>
        /// Dozwolone możliwości dla Type: "info", "success", "error", "warning"
        /// </summary>
        [HttpGet("showPopup/{deviceId}/{type}/{message}")]
        public void ShowToast(string deviceId, string type, string message)
        {
            _appStateService.OnToastAction(deviceId, type, message);
            return;
        }

    }
}
