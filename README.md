# ESP8266-Proxmox-API
Control your Proxmox VMs with your ESP8266

## How to use:
1. Create an API User on your Proxmox Machine (as shown below)
2. Download Code and Update the Variables
3. Have Fun!

## Important:
> More Information to the Permissions and API Commands can be found here: https://pve.proxmox.com/pve-docs/api-viewer/index.html

## Extended Instructions:
### 1. Go to `Datacenter` in the List on the left

![menu_permissions](https://user-images.githubusercontent.com/35042685/194409203-ebc125b3-a7bb-4a70-bae9-fb52e540eb62.PNG)
- Search in the Menu for `Permissions`. Then click on `Users`.

### 2. Create a new User on the Proxmox Machine

![create_user](https://user-images.githubusercontent.com/35042685/194408336-defb2359-6d05-4d1e-be22-bc7fa63b091e.PNG)
- Give it a Name.
- Choose "Proxmox VE authentication server" in the field "Realm".
- Add a secure password.

### 3. Create a new API Token

![create_apitoken](https://user-images.githubusercontent.com/35042685/194409792-2219ab8d-40cd-40bd-bb0b-2b16ed55af61.PNG)
- Go to `API Tokens` in the Menu
- Insert the User you created.
- Give it an ID or Name.
- When you finished, click on `Add` and note the two secret values shown! Do not forget as this will never be shown again.

### 4. Create a Role

![image](https://user-images.githubusercontent.com/35042685/194411987-fb4a3acb-06b5-4fe3-ba87-dea93350f8c4.png)
- Go to the Menu and Click `Roles`
- Add a new Role
- Give it a Name
- Add the Permissions needed (for Example: `VM.PowerMgmt` is needed for Starting and Stopping a VM)
> More Information to the Permissions can be found here: https://pve.proxmox.com/pve-docs/api-viewer/index.html

### 5. Add the Permission to the User and the API

![add_permission](https://user-images.githubusercontent.com/35042685/194410926-d73e384c-e57c-4677-b711-2b751ec2b22b.png)
- Go in the Menu to `Permissions`
- Click on `Add` and then on `User Permissions`

![image](https://user-images.githubusercontent.com/35042685/194411497-95e62ae4-8839-467e-9ea2-075d30dbdb91.png)
- Select the Path `/`, insert the User you created and insert the Role you created
- Then click add and Repeat this process with `API Token Permission`

### 6. Update Arduino Code
Now update the Variables in the Arduino Code and Execute it. It should work.
